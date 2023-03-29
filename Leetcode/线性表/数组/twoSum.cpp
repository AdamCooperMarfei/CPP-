#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;
//Two Sum
class Solution1{
public:
    vector<int> TwoSum(vector<int>&nums, int target){
        unordered_map<int, int> mapping;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i){
            mapping[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); ++i){
            const int gap = target - nums[i];
            if(mapping.find(gap) != mapping.end() && mapping[gap] > i){
                result.push_back(i + 1);
                result.push_back(mapping[gap] + 1);
                break;
            }
        }
        return result;
    }
};
// Three Sum
class Solution2{
public:
    vector<vector<int>> ThreeSum(vector<int>&nums){
        vector<vector<int>> result;
        if(nums.size() < 3){
            return result;
        }
        sort(nums.begin(), nums.end());
        const int target = 0;
        auto last = nums.end();
        for(auto i = nums.begin(); i != last - 2; ++i){
            auto j = i + 1;
            if(i > nums.begin() && *i ==*(i - 1)){
                continue;
            }
            auto k = last - 1;
            while (j < k)
            {
                /* code */
                if(*i + *j + *k < target){
                    ++j;
                    while (*j == *(j - 1) && j < k)
                    {
                        /* code */
                        ++j;
                    }
                }
                else if (*i + *j + *k > target)
                {
                    /* code */
                    --k;
                    while (*k == *(k + 1) && j < k)
                    {
                        /* code */
                        --k;
                    }
                }
                else{
                    result.push_back({*i, *j, *k});
                    ++j;
                    --k;
                    while(*j == *(j - 1) && *k == *(k + 1) && j < k){
                        ++j;
                    }
                }   
            }
        }
        return result;
    }
};
// three sum closest
class Solution3{
public:
    int ThreeSumCloset(vector<int>&nums, int target){
        int result = 0;
        int min_gap = INT_MAX;
        sort(nums.begin(), nums.end());
        for(auto a = nums.begin(); a != prev(nums.end(), 2); ++a){
            auto b = next(a);
            auto c = prev(nums.end());
            while(b < c){
                const int sum = *a + *b + *c;
                const int gap = abs(sum - target);
                if(gap < min_gap){
                    result = sum;
                    min_gap = gap;
                }
                if(sum < target){
                    ++b;
                }
                else{
                    --c;
                }
            }
        }
        return result;
    }
};