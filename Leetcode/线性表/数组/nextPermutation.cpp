#include<vector>
#include<algorithm>
#include<cstddef>
#include<functional>
using namespace std;
//下一个排序（字典序）
class Solution{
public:
    void nextPermutation(vector<int>&nums){
        next_permutation(nums.begin(), nums.end());
    }
    template<typename BidiIt>
    bool next_permutation(BidiIt first, BidiIt last){
        //get a reversed range to simplify reversed traversal
        const auto rfirst = reverse_iterator<BidiIt>(last);
        const auto rlast = reverse_iterator<BidiIt>(first);
        //begin from the second last element to the first element
        auto pivot = next(rfirst);
         // Find `pivot`, which is the first element that is no less than its
         // successor.  `Prev` is used since `pivort` is a `reversed_iterator`.
         while(pivot != rlast && *pivot >= prev(pivot))
            ++pivot;
          // No such elemenet found, current sequence is already the largest
          // permutation, then rearrange to the first permutation and return false.
        if(pivot == rlast){
            reverse(rfirst, rlast);
            return false;
        }
          // Scan from right to left, find the first element that is greater than
          // `pivot`.
        auto change = find_if(rfirst, pivot, bind1st(less<int>, *pivot));
        swap(*change, *pivot);
        reverse(rfirst, pivot);
        return true;
    }
};