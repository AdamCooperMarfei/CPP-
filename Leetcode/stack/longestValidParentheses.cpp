#include<string>
#include<stack>
#include<vector>
using namespace std;
class Solution{
public:
    int longestValidParenthese(const string &s){
        int max_len = 0;
        int last = -1;
        stack<int> lefts;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(')
                lefts.push(i);
            else{
                if(lefts.empty())
                    last = i;
                else{
                    lefts.pop();
                    if(lefts.empty())
                        max_len = max(max_len, i - last);
                    else{
                        max_len = max(max_len, i - lefts.top());
                    }
                }
            }
        }
        return max_len;
    }
};

//dynamic programming
class Solution2{
public:
    int longestValidParentheses(const string &s){
        vector<int> f(s.size(), 0);
        int rec = 0;
        for(int i = f.size() - 2; i >= 0; --i){
            int match = i + f[i + 1] + 1;
            
        }
        
    }
};