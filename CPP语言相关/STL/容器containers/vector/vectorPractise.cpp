#include<iostream>
#include<vector>

int main()
{
    //vector::operator =
    std::vector<int> foo(3, 0);
    std::vector<int> bar(5, 0);
    bar = foo;
    foo = std::vector<int>();
    std::cout<<"size of bar: "<<int(bar.size())<<std::endl;
    std::cout<<"size of foo: "<<int(foo.size())<<std::endl;
    //size()
    std::vector<int>myInts;
    std::cout<<"initial size: "<<int(myInts.size())<<std::endl;
    
    return 0;

    
}