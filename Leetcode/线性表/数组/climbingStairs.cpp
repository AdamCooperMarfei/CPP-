#include<vector>
#include<math.h>
using namespace std;
class Solution1{
public:
    int climbStaris(int n){
        int prev = 0;
        int cur = 1;
        for(int i = 1; i <= n; ++i){
            int temp = cur;
            cur += prev;
            prev = temp;
        }
        return cur;
    }
};

class Solution2{
public:
    int climbStairs(int n){
        const double s = sqrt(5);
        return floor((pow((1 + s) / 2, n + 1) + pow((1 - s) / 2, n + 1)) / s + 0.5);
    }
};