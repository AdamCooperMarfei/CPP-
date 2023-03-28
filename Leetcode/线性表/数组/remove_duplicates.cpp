#include <vector>
#include<iostream>
using namespace std;
//Remove Duplicates from Sorted Array
class Solution1{
public:
    int removeDuplicates(vector<int>&nums){
        //Returns the number of hops from first to last.
        return distance(nums.begin(), removeDuplicate(nums.begin(), nums.end(), nums.begin()));
    }
    template<typename InIt, typename OutIt>
    OutIt removeDuplicate(InIt first, InIt last, OutIt output){
        while (first != last)
        {
            /* code */
            //同级别运算符，从右至左，由于是后置++，因此先取值然后再自增 
            *output++ = *first;
            //upper bound返回的是一个迭代器，第一个大于value的element的迭代器
            first = upper_bound(first, last, *first);
        }
        return output;
    }
};
class Solution2{
public:
    int removeDuplicates(vector<int>&nums){
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
};
class Solution3{
public:
    int removeDuplicates(vector<int>&nums){
        if(nums.empty()){
            return 0;
        }
        int index = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[index] != nums[i]){
                nums[++index] = nums[i];
            }
        }
    }
};
//Remove Duplicates from Sorted Array II
class Solution4{
public:
    int removeDuplicates(vector<int>&nums){
        if (nums.size() <= 2){
            return nums.size();
        }
        int index = 2;
        for(int i = 2; i<nums.size();i++){
            if(nums[i] != nums[index - 2]){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};

class Solution5{
public:
    int removeDuplicates(vector<int>&nums){
        const int n = nums.size();
        int index = 0;
        for(int i = 0;i < n;++i){
            if(i > 0 && i < n && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
            continue;
            nums[index++] = nums[i];
        }
        return index;
    }
};