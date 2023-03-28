#include<iostream>
#include<vector>
using namespace std;
class Soltion1{
public:
    int search(const vector<int>nums, int value){
        int first = 0;
        int last = nums.size();
        while (first != last)
        {
            /* code */
            const int mid = first + (last - first) / 2;
            if (nums[mid] == value)
            return mid;
            if (nums[first] <= nums[mid]){
                if(nums[first] <= value &&value < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            }
            else{
                if(nums[mid] < value && value <= nums[last])
                    first = mid +1;
                else
                    last = mid;
            }
        }
        return -1;
    }
};