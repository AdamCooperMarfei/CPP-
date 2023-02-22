##### Stack_note

同样，栈stack是后进先出（LIFO) 的数据结构

stack缺省也是用deque来实现，但它的概念和vector更相似。它的接口根vector比，有如下改变

- 不能按下标访问元素
- 没有begin，end成员函数
- back成了top，没有front
- 用emplace替代了emplace_back，用push替代了push_back，用pop替代了pop_front；没有其他的push_...,pop_...,emplace...,insert,erase函数

一般图形表示法会把stack表示成一个竖起的vector。

stack：下面是低地址，向上则地址增大

内存管理的栈：高地址在下面，向上则地址减小

###### 为什么stack或queue函数返回类型为void，而不直接放回容器的top或front成员？

这是cpp98里，还没有移动语义时的设计。如果pop返回元素，而元素拷贝时发生异常，那这个元素就丢失了。因而容器设计成有分离的top（或front）和pop成员函数，分别执行访问和弹出的操作。

有一种可能的设计是把接口改成void pop(T &)，这增加了T必须支持默认构造和赋值的要求，在单线程为主的年代没有明显的好处，反而带来了对T的额外要求。