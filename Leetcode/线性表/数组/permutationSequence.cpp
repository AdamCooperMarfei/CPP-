#include<vector>
#include<string>
using namespace std;
class Solution1{
public:
    string getPermutation(int n, int k){
        string s(n, '0');
        for(int i = 0;i < n; ++i){
            s[i] += i + 1;
        }
        for(int i = 0; i < k; ++i){
            next_permutation(s.begin(), s.end());
        }
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
class Solution2{
public:
    string getPermutation(int n, int k){
        string s(n, '0');
        for(int i = 0; i< n; ++i){
            s[i] += i + 1;
        }
        return kth_permutation(s, k);
    }
private:
    int factorial(int n){
        int result = 1;
        for(int i = 1; i <= n; ++i){
            result *= i;
        }
        return result;
    }
    template<typename Sequence>
    Sequence kth_permutation(const Sequence&seq, int k){
        const int n = seq.size();
        Sequence S(seq);
        Sequence result;
        int base = factorial(n - 1);
        --k;
        for(int i = n - 1;i > 0; k %= base, base /= i, --i){
            auto a = next(S.begin(), k / base);
            result.push_back(*a);
            S.erase(a);
        }
        result.push_back(S[0]);
        return result; //最后一个
    }
};