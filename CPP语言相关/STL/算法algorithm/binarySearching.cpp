#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//以普通函数的方式定义查找规则
bool myComp(int i, int j)
{
    return i>j;
}
//以函数对象的形式定义查找规则
class myComp2
{
    public:
    bool operator()(const int &i, const int &j)
    {
        return i>j;
    }
};
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    //在a中查找第一个不小于3的元素
    int *p = lower_bound(a, a+5, 3);
    cout<<"*p= "<<*p<<endl;
    vector<int> myVector = {4, 5, 3, 1, 2};
    //根据mycomp2的查找规则，找到第一个违背mycomp2规则的元素
    vector<int> ::iterator iter = lower_bound(myVector.begin(), myVector.end(), 3,myComp2());
    cout<<"*iter= "<<*iter<<endl;
    return 0;
}


