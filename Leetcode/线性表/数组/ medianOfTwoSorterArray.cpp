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

    }
};