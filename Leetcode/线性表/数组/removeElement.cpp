#include<vector>
using namespace std;
//1、从左到右扫描，维护一个索引，这个索引始终保持为新数组的最后一位。
//2、如果扫描到了一个元素不等于val，则将索引+1，且索引对应的值修改为当前元素值。
//3、此方法不会改变数组的长度
class Solution1{
public:
    int removeElement(vector<int> &nums, int target){
        int index = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != target){
                nums[index ++] = nums[i];
            }
        }
        return index;
    }
};
//使用remove
class Solution2{
public:
    int removeElement(vector<int>&nums, int target){
        return distance(nums.begin(), remove(nums.begin(), nums.end(), target));
    }
};