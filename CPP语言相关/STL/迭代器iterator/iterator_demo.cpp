#include<iterator>
#include<algorithm>
#include<vector>
#include<iostream>

int main()
{
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2;
    std::copy(v1.begin(), v1.end(),std::back_inserter(v2));
    for (int &x:v2)
    {
        /* code */
        std::cout<<x<<' ';
    }
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    //使用输入行迭代器   
    
}