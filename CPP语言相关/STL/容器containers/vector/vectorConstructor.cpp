#include<iostream>
#include<vector>
int main()
{
    //empty vector of ints(default)
    std::vector<int> first;
    //fill constructor
    std::vector<int> second(4, 100); // four ints with value 100
    //range constructor
    std::vector<int> third(second.begin(), second.end());
    //copy constructor
    std::vector<int> fourth(third);
    //move constructor
    int myInts[] = {18, 9, 55, 20};
    std::vector<int> fifth(myInts, myInts+sizeof(myInts)/sizeof(int));
    std::cout<<"the contents of fifth are\n";
    for (std::vector<int>::iterator it = fifth.begin(); it !=fifth.end(); ++it)
    {
        /* code */
        std::cout<<' '<<*it;
    }
    return 0;
    
}