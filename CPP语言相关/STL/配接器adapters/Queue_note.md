##### Queue_note

之所以叫做适配器，是因为其不是完整的实现，而是依赖于某个现有的容器，因此叫container adapter。

队列queue，先进先出(fifo)的数据结构。

queue缺省用deque。他的接口根deque相比，有如下改变：

- 不能按下标访问元素
- 没有begin，end成员函数
- 用emplace替代了emplace_back，用push替代了push_back，用pop替代了pop_front；没有其他的push_...,pop_...,emplace...,insert,erase函数

他的实际内存布局当然是随着底层的容器而定的，因此其内存也是连续的。