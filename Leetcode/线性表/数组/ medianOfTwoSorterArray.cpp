#include<vector>
using namespace std;
//两个排序好的数组，找出第k大的元素
class Solution1{
public:
    double findMedianOfTwoSortedArray(vector<int>&A, vector<int>&B){
        const int m = A.size();
        const int n = B.size();
        int total = m + n;
        if(total & 0x1)
            //total is odd
            return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
        else
            //total is even
            return (find_kth(A.begin(), m, B.begin(), n, total / 2) + 
                find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;

    }
private:
    static int find_kth(vector<int>::const_iterator A, int m, 
    vector<int>::const_iterator B, int n, int k){
        if(m > n) return find_kth(B, n, A, m, k);
        if(m == 0) return *(B + k - 1);
        if(k = 1) return min(*A, *B);
        //divide k into two parts
        int ia = min(k / 2, m), ib = k - ia;
        if(*(A + ia - 1) < *(B + ib - 1))
            return find_kth(A + ia, m - ia, B, n, k - ia);
        else if(*(A + ia - 1) > *(B + ib - 1))
            return find_kth(A, m, B + ib, n - ib, k - ib);
        else
            return A[ia - 1];

    }
};