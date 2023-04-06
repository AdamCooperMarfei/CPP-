#include<vector>
#include<stack>
using namespace std;
class Solution1{
public:
    int trappingRainWater(const vector<int>&nums){
        const int n = nums.size();
        int *max_left = new int[n]();
        int *max_right = new int[n]();
        for(int i = 1; i < n; ++i){
            max_left[i] = max(max_left[i - 1], nums[i - 1]);
            max_right[n - i - 1] = max(max_right[n - i], nums[n - i]);
        }
        int sum = 0;
        for(int i = 0; i < n; ++i){
            int height = min(max_left[i], max_right[i]);
            if(height > nums[i]) sum += height - nums[i];
        }
        delete[]max_left;
        delete[]max_right;
        return sum;
    }
};

class Solution2{
public:
    int trappingRainWater(const vector<int>&nums){
        const int n = nums.size();
        int max = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] > nums[max]) max = i;
        }
        int water = 0;
        for(int i = 0, peak = 0; i < max; ++i){
            if(nums[i] > peak) peak = nums[i];
            else water += peak - nums[i];
        }
        for(int i = n - 1, top = 0; i > max; --i){
            if(nums[i] > top) top = nums[i];
            else water += top - nums[i];   
        }
        return water;
    }
};


class Solution3{
public:
    int trappingRainWater(const vector<int>&nums){
        const int n = nums.size();
        stack<pair<int, int>> s;
        int water = 0;
        for(int i = 0; i < n; ++i){
            int height = 0;
            while(!s.empty()){
                int bar = s.top().first;
                int pos = s.top().second;
                water += (min(bar, nums[i]) - height) * (i - pos - 1);
                height = bar;
                if(nums[i] < bar) break;
                else s.pop();
            }
            s.push(make_pair(nums[i], i));
        }
        return water;
    }
};