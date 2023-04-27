#include<memory>
#include<iostream>
#include<string>
int main(){
    std::allocator<int> alloc1;
    static_assert(std::is_same_v<int, decltype(alloc1)::value_type>);
    //space for one int
    int *p1 = alloc1.allocate(1);
    //and it is gone
    alloc1.deallocate(p1, 1);
    using traits_t1 = std::allocator_traits<decltype(alloc1)>;
    





}