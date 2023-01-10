#### array

------

array是固定大小的顺序容器，它们保存了一个以严格的线性顺序排列的特定数量的元素。

在内部，一个数组除了它所包含的元素（甚至不是他的大小，它是一个模版参数，在编译时是固定的）以外不保存任何数据。存储大小与用语言括号语法（[]）声明的普通数组一样高效。这个类只是增加了一层成员函数和全局函数，所以数组可以作为标准容器使用。

与其他标准容器不同，数组具有固定的大小，并且不通过分配器管理其元素的分配：它们是封装固定大小数组元素的聚合类型。因此，它们不能动态地扩大或缩小。

零大小的数组是有效的，但是它们不应该被解除引用（成员的前面后面和数据）

与标准库的其他容器不同，交换两个数组容器是一种线性操作，它涉及单独交换范围内的所有元素，这通常是相当低效的操作。另一方面，这允许迭代器在两个容器中的元素保持其原始容器关联。

数组容器的另一个独特特性是他们可以被当作元组对象来处理：array头部重载get函数来访问数组元素，就像它是一个元祖，以及专门的tuple_size和tuple_element类型。

```c++
template<class T, size_t N> class array;
```

- array::begin

返回指向数组容器中第一个元素的迭代器。

```c++
iterator begin() noexcept;
const_iterator begin() const noexcept;
```

- array::end

返回指向数组容器中最后一个元素之后的理论元素的迭代器。

```c++
iterator end() noexcept;
const_iterator end() const noexcept;
```

- array::rbegin

返回指向数组容器中最后一个元素的反向迭代器

```c++
reverse_iterator rbegin() noexcept;
const_reverse_iterator rbegin() const noexcept;
```

- array::cbegin

返回指向数组容器中第一个元素的常量迭代器（const_iterator）：这个迭代器可以增加和减少，但是不能用来修改它指向的内容。

```c++
const_iterator cbegin() const noexcept;
```

- array::cend

返回指向数组中最后一个元素之后的理论元素的常量迭代器。这个迭代器可以增加和减少，但是不能用来修改它指向的内容。

```c++
const_iterator cend() const noexcept;
```

- array::crbegin

返回指向数组元素中最后一个元素的常量反向迭代器

```c++
const_reverse_iterator crbegin() const noexcept;
```

- array::crend

返回指向数组中第一个元素之前的理论元素的常量反向迭代器，其被认为是反向结束

```c++
const_reverse_iterator crend() const noexcept;
```

- array::size

返回数组容器中元素的数量

```c++
constexpr size_type size() noexcept;
```

- array::max_size

返回数组容器可容纳的最大元素数。数组对象的max_size与其size一样，始终等于实例化数组模版类的第二个模板参数。

- array::empty

返回一个布尔值，指示数组容器是否为空，即他的size()是否为0

- array::operator[]

返回数组中第n个位置的元素的引用。与array::at相似，但array::at会检查数组边界并通过抛出一个out_of_range异常来判断n是否超出范围，而array::operator[]不检查边界。

```c++
reference operator[] (size_type n);
const_reference operator[](size_type n) const;
```

- array::at

返回数组中第n个位置的元素的引用。与array::operator[]相似，但array::at会检查数组边界并通过抛出一个out_of_range异常来判断n是否超出范围，而array::operator[]不会检查边界

```c++
reference at(size_type n);
const_reference at(size_type n) const;
```

- array::front

返回对数组容器中第一个元素对引用。array::begin返回对是迭代器，array::front返回的是直接引用。在空容器上调用此函数会导致未定义的行为。

```c++
reference front();
const_reference front() const;
```

- array::back

返回对数组容器中最后一个元素的引用。array::end返回的是迭代器，array::back返回的是直接引用。在空函数上调用此函数会导致未定义的行为。

```c++
reference back();
const_reference back() const;
```

- array::data

返回指向数组对象中第一个元素的指针。

由于数组中的元素存储在连续的存储位置，所以检索到的指针可以偏移以访问数组中的任何元素。

```c++
value_type* data() noexcept;
const value_type* data() const noexcept;
```

- arrar::fill

用val填充数组所有元素，将val设置为数组对象中所有元素的值。

```c++
void fill(const value_type& val);
```

- array::swap

通过x的内容交换数组的内容，这是另一个相同类型的数组对象（包括相同的大小）。

与其他容器的交换成员函数不同，此成员函数通过在各个元素之间执行与其大小相同的单独交换操作，以线性时间运行。

```c++
void swap(array& x) noexcept(noexcept(swap(declval<value_type&>(),declval<value_type&>())));
```

- get(array)

形如：std::get<0>(myarray);传入一个数组容器，返回指定位置元素的引用。

```c++
template<size_t I, class T, size_t N>T&get(array<T,N>&arr) noexcept;
template<size_t I, class T, size_t N>T&&get(array<T, N>&&arr)noexcept;
template<size_t I, class T, size_t N>const T&get(const array<T, N>&arr)noexcept;
```

