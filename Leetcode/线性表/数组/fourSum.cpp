#include<vector>
#include<unordered_map>
using namespace std;
class Solution1{
public:
    //先排序然后左右夹逼
    vector<vector<int>> fourSum(vector<int>&nums, int target){
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        auto last = nums.end();
        for(auto a = nums.begin(); a < prev(last, 3); ++a){
            for(auto b = next(a); b < prev(last, 2); ++b){
                auto c = next(b);
                auto d = prev(last);
                while(c < d){
                    if(*a + *b + *c + *d < target){
                        ++c;
                    }
                    else if(*a + *b + *c + *d > target){
                        --d;
                    }
                    else{
                        result.push_back({*a , *b , *c , *d });
                        ++c;
                        --d;
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};

class Solution2{
public:
    //map做缓存
    //用一个hashmap先缓存两个数的和
    vector<vector<int>>fourSum(vector<int>&nums, int target){
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>>> cache;
        for(size_t a = 0; a < nums.size(); ++a){
            for(size_t b = a + 1; b < nums.size(); ++b){
                cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
            }
        }
        for(int c = 0; c < nums.size(); ++c){
            for(size_t d = c + 1; d < nums.size(); ++d){
                const int key = target - nums[c] - nums[d];
                if(cache.find(key) == cache.end()) continue;
                const auto & vec = cache[key];
                for(size_t k = 0; k < vec.size(); ++k){
                    if(c < vec[k].second){
                        continue;
                    }
                    result.push_back({nums[vec[key].first], nums[vec[key].second], nums[c], nums[d]});
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
//用一个hashmap先缓存两个数的和
class Solution3{
public:
    vector<vector<int>> fourSum(vector<int>&nums, int target){
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        unordered_map<int, pair<int, int>> cache;
        for(int i = 0; i + 1<nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
            }
        }
        for(auto i = cache.begin(); i != cache.end(); ++i){
            int x = target - i->first;
            auto range = cache.equal_range(x);
            for(auto j = range.first; j != range.second; ++j){
                auto a = i->second.first;
                auto b = i->second.second;
                auto c = j->second.first;
                auto d = j->second.second;
                if(a != c && a != d && b != c && b != d){
                    vector<int> vec = {nums[a], nums[b], nums[c], nums[d]};
                    sort(vec.begin(), vec.end());
                    result.push_back(vec);
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};

class Solution4{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        auto last = nums.end();
        for(auto a = nums.begin(); a < prev(last, 3); a = upper_bound(a, prev(last, 3), *a)){
            for(auto b = next(a); b < prev(last, 2); b = upper_bound(b, prev(last, 2), *b)){
                auto c = next(b);
                auto d = prev(last);
                while (c < d)
                {
                    if(*a + *b + *c + *d < target){
                        c = upper_bound(c, d, *c);
                    }
                    else if (*a + *b + *c + *d > target){
                        d = prev(lower_bound(c, d, *d));
                    }
                    else{
                        result.push_back({*a , *b , *c , *d });
                        c = upper_bound(c, d, *c);
                        d = prev(lower_bound(c, d, *d));
                    }
                }
            }
        }
        return result;
    }
};