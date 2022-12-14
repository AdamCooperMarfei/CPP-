###### vector

实际的应用中基本上是将其当作动态数组更为合适一点。其相当于java的ArrayList和python的list。

和string相似，vector的成员在内存中连续存放，同时begin，end，front，back成员函数指向的位置也和string一样。

除了容器类的共同点，vector还允许下面点操作：

- 可以使用中括号的下标来访问其成员（同string）
- 可以使用data来获得其指向内容的裸指针（同string）？
- 可以使用capacity来获得当前分配的存储空间的大小，以元素数量计（同string）
- 可以使用reserve来改变所需存储空间的大小，成功后capacity（）会改变（同string）
- 可以使用resize来改变其大小，成功后size（）会改变（同string）
- 可以使用pop_back来删除最后一个元素（同string）
- 可以使用push_back在尾部插入一个元素（同string）
- 可以使用insert在指定位置前插入一个元素（同string）
- 可以使用erase在指定位置删除一个元素（同string）
- 可以使用emplace在指定位置构造一个元素
- 可以使用emplace_back在尾部构造一个元素

对于push_...or pop_...成员函数。若他们存在则说明容器对指定位置的删除和插入性能较高。vector适合在尾部插入，这是由他的内存布局决定的。只有在尾部插入和删除时，其他元素才不需要移动，除非内存空间不足导致需要重新分配内存空间。

当push_back,insert,reserve,resize等函数导致内存重新分配时，或者当insert，erase导致元素位置移动时，vector会试图把元素“移动”到新的内存区域内。vector通常保证强异常安全性，如果元素类型没有提供一个保证不抛异常的移动构造函数，那么vector通常会使用拷贝构造函数。因此，对于拷贝代价较高的自定义元素类型，我们应当定义移动构造函数，并标其为noexcept，或只在容器中放置对象的智能指针。这就是为什么需要在智能指针的实现中标上no except的原因。

见cpp中stl容器vector部分：obj1与obj2的定义之差一个no except，但这个小小的差异就导致了vector是否会移动对象。

c++11开始提供的emplace系列函数是为了提高容器性能而设计的。可以尝试把

```c++
v1.emplace_back();
```

修改为

```c++
v1.push_back(Obj1());
```

这样对于vector里的内容，结果是一样的；但使用pushback会额外生成临时对象，多一次（移动或拷贝）构造和析构。如果是移动的情况，会有小幅性能损失；如果对象没有实现移动，那性能的差异就可能比较大了。

现代处理器的体系架构使得对连续内存的访问速度比不连续的内存要快的多。因而，vector的连续内存使用是它的一大优势所在。

vector的一个主要缺陷是大小增长时导致元素移动。如果可能，需要尽早使用reserve函数为vector保留所需的内存，这在vector预期会增长很大时带来很大的性能提升。

##### vector越界访问下标？

通过下标访问vector中的元素不会做边界检查，即使下标越界。

也就是说，下标与first迭代器相加的结果超过了finish迭代器的位置，程序也不会报错，而是返回这个地址中存储的值。

如果想在访问vector中的元素时首先进行边界检查，可以使用vector中的at函数。通过使用at函数不但可以通过下标访问vector中的元素，而且at函数会在内部对下标进行边界检查。

##### STL中vector删除其中的元素，迭代器如何变化？为什么是两倍扩容？释放空间？

size函数返回的是已用空间的大小，capacity返回的是总空间大小，capacity()-size()则是剩余的可用空间大小。当size与capacity相等时，说明vector内的空间已经全部用完，如果再添加新元素，就会引起vector空间的动态增长。

由于动态增长会引起重新分配内存空间，拷贝原空间，释放原空间，这些过程会降低程序效率。因此可以使用reserve(n)预先分配一块较大的指定大小的内存空间，这样当指定大小的内存空间为使用完时，是不会重新分配内存空间的，这样便提升了效率。

resize函数只改变元素的数量，不改变vector的容量。

1. 空的vector对象，size(),capacity()都为0
2. 当空间大小不足时，新分配的空间大小为原空间大小的两倍
3. 使用reserve函数预先分配了一块内存后，在空间未满的情况下，不会引起重新分配，从而提升了效率
4. 当reserve分配的空间比原空间小时，是不会引起重新分配的
5. resize函数只改变元素的数量，不改变vector的容量
6. 用reserve(size_type)只是扩大capacity值，这些内存空间还是“野”的，如果用中括号来访问，则可能会越界。而resize(size_type new_size)会真正使容器具有new_size个对象

不同的编译器，vector有不同的扩容大小。在vs是1.5倍，在gcc是2倍。

使用k=2赠长因子的问题在于，每次扩展的新尺寸必然刚好大于之前分配的总和，也就是说之前分配的内存空间不可能被使用。这样对内存不友好。

对比可以发现采用成倍方式扩容，可以保证常数的时间复杂度，而增加指定大小的容量只能达到O(n)的时间复杂度，因此采用成倍的方法扩容。

如何释放空间：

由于vector的内存占用空间只增不减，比如首先分配了10000个字节，然后erase后面的9999个，留有一个有效元素，但是内存占用仍为10000个。所有内存空间是在vector析构时才能被系统回收。empty用来检查容器是否为空，clear可以清楚所有元素。但是即使clear，vector所占用的内存空间依旧如故，无法保证内存的回收。

如果需要空间动态缩小，可以考虑使用deque。如果是vector，可以用swap来释放内存

```c++
vector(Vec).swap(Vec);
//将Vec的内存空洞清除
vector().swap(Vec);
//清空Vec的内存
```

