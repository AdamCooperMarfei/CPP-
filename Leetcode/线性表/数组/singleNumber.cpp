#include<vector>
#include<numeric>
using namespace std;
class Solution1{
public:
    int singleNumber(vector<int>&nums){
        int x = 0;
        for(auto i : nums){
            x ^= i;
        }
        return x;
    }
};

class Solution2{
public:
    int singleNumber(vector<int>&nums){
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};

class Solution3{
public:
    int singleNumber(vector<int>&nums){
        const int W = sizeof(int) * 8;
        int count[W];
        fill_n(&nums[0], W, 0);
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < W; ++j){
                count[j] += (nums[i] >> j)&1;
                count[j] %= 3;
            }
        }
        int result = 0;
        for(int i = 0; i < W; ++i){
            result += (count[i] << i);
        }
        return result;
    }
};

class Solution4{
public:
    int singleNumbers(vector<int>&nums){
        int one = 0, two = 0, three = 0;
        for(auto i : nums){
            two |= (one & i);
            one ^= i;
            three = ~(one & two);
            one &= three;
            two &= three;
        }
        return one;
    }
};