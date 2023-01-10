#include<iostream>
#include<array>
#include<tuple>
int main()
{
    std::array<int, 5> myarray = {2, 16, 5, 61, 90};
    std::cout<<"myarray contains"<<std::endl;
    std::cout<<"begin用法:"<<std::endl;
    for (auto i = myarray.begin(); i < myarray.end(); ++i)
    {
        /* code */
        std::cout<<' '<<*i<<std::endl;
    }
    std::cout<<"end用法:"<<std::endl;
    for (auto i = myarray.begin(); i != myarray.end(); ++i)
    {
        /* code */
        std::cout<<' '<<*i<<std::endl;
    }
    std::cout<<"rbegin和rend用法:"<<std::endl;
    for (auto i = myarray.rbegin(); i < myarray.rend(); ++i)
    {
        /* code */
        std::cout<<' '<<*i<<std::endl;
    }
    std::cout<<"cbegin和cend用法:"<<std::endl;
    for (auto i = myarray.cbegin(); i != myarray.cend(); ++i)
    {
        /* code */
        std::cout<<' '<<*i<<std::endl;//不能更改i的内容
    }
    std::cout<<"crbegin和crend用法"<<std::endl;
    for (auto i = myarray.crbegin(); i < myarray.crend(); ++i)
    {
        /* code */
        std::cout<<' '<<*i<<std::endl;
    }
    std::cout<<"size of myarray: "<<myarray.size()<<std::endl;
    std::cout<<"sizeof myarray: "<<sizeof(myarray)<<std::endl;
    std::cout<<"max size of myarray: "<<myarray.max_size()<<std::endl;
    std::array<int, 5> first = {10, 20, 30, 40, 50};
    std::array<int, 5> second = {11, 12, 13, 14, 15};
    std::cout<<"first "<<(first.empty()? "is empty":"is not empty")<<std::endl;
    std::cout<<"secont "<<(second.empty()? "is empty": "is not empty")<<std::endl;
    first.swap(second);
    for (int& x:first)
    {
        /* code */
        std::cout<<x<<' ';
    }
    std::cout<<'\n';
    for (int&x:second)
    {
        /* code */
        std::cout<<x<<' ';
    }
    std::cout<<'\n';
    for (int i = 0; i < myarray.size(); ++i)
    {
        /* code */
        myarray[i] = i;
    }
    for (auto i = myarray.begin(); i < myarray.end(); ++i)
    {
        /* code */
        std::cout<<*i;
    }
    std::cout<<std::endl;
    for (int i = 0; i < myarray.size(); ++i)
    {
        /* code */
        std::cout<<myarray.at(i);
    }
    std::cout<<std::endl;
    std::cout<<"myarray front is: "<<myarray.front()<<std::endl;
    std::cout<<"myarray back is: "<<myarray.back()<<std::endl;
    myarray.front() = 100;
    myarray.back() = 50;
    for (int &x:myarray)
    {
        /* code */
        std::cout<<' '<<x;
    }
    std::cout<<'\n';
    const char* cstr = "test string";
    std::array<char, 12> chararray;
    std::memcpy(chararray.data(), cstr, 12);
    std::cout<<chararray.data()<<'\n';
    myarray.fill(40);
    for (int &x:myarray)
    {
        /* code */
        std::cout<<x<<' ';
    }
    std::cout<<'\n';
    std::tuple<int, int, int> mytuple (10, 20, 30);
    //int myelement
    std::tuple_element<0, decltype(myarray)>::type myelement;
    myelement = std::get<2> (myarray);
    




    return 0;
}
