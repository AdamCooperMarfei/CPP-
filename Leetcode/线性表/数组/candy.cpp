#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution1{
public:
    int candy(vector<int>&ratings){
        const int n = ratings.size();
        vector<int> increment(n);
        for(int i = 1, inc = 1; i < n; ++i){
            if(ratings[i] > ratings[i - 1])
                increment[i] = max(inc++, increment[i]);
            else
                inc = 1;
        }
        for(int i = n - 2, inc = 1; i >= 0; --i){
            if(ratings[i] > ratings[i + 1])
                increment[i] = max(inc++, increment[i]);
            else
                inc = 1;
        }
        return accumulate(increment.begin(), increment.end(), n);
    }
};

class Solution2{
public:
    int candy(vector<int>&ratings){
        const int n = ratings.size();
        vector<int> increment(n);
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += solve(ratings, increment, i);
        }
        return sum;
    }
    int solve(const vector<int>&ratings, vector<int>&increment, int i){
        if(increment[i] == 0){
            increment[i] = 1;
            if(i > 0&&ratings[i] > ratings[i - 1])
                increment[i] = max(increment[i], solve(ratings, increment, i- 1) + 1);
            if(i < ratings.size() - 1&&ratings[i] > ratings[i + 1])
                increment[i] = max(increment[i], solve(ratings, increment, i + 1) + 1);
        }
        return increment[i];
    }
};