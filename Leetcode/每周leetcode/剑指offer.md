##### 剑指offer

###### hash

- 004.只出现一次的数字 

给你一个整数数组 `nums` ，除某个元素仅出现 **一次** 外，其余每个元素都恰出现 **三次 。**请你找出并返回那个只出现了一次的元素。

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num:nums)
        {
            ++freq[num];
        }
        int ans = 0;
        for(auto &pair:freq)
        {
            if(pair.second == 1)
            {
                ans = pair.first;
            }
        }
        return ans;
    }
};
```

- 005.单词长度的最大乘积

给定一个字符串数组 `words`，请计算当两个字符串 `words[i]` 和 `words[j]` 不包含相同字符时，它们长度的乘积的最大值。假设字符串中只包含英语的小写字母。如果没有不包含相同字符的一对字符串，返回 0。