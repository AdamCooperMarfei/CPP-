#include<string>
using namespace std;
class Solution{
public:
    int implementStr(const string& haystack, const string& needle){
        if(needle.empty()) return 0;
        const int N = haystack.size() - needle.size() + 1;
        for(int i = 0; i < N; ++i){
            int j = i;
            int k = 0;
            while (j < haystack.size() && k<needle.size()&&haystack[j] == needle[k]){
                ++j;
                ++k;
            }
            if(k = needle.size()) return i;
        }
        return -1;
    }
};

class Solution2{
public:
    int implementStr(const string& haystack, const string& needle){
        return kmp(haystack.c_str(), needle.c_str());
    }
private:
    static int kmp(const char *text, const char *pattern){
        int i;
        int j = -1;
        const int n = strlen(text);
        const int m = strlen(pattern);
        if(n == 0 && m ==0) return 0;
        if(m == 0) return 0;
        int *next = (int *)malloc(sizeof(int) * m);
        compute_prefix(pattern, next);
        for(i = 0; i < n; ++i){
            while (j > -1 && pattern[j + 1] != text[i]) j = next[j];
            if(text[i] == pattern[j + 1]) j++;
            if(j == m - 1){
                free(next);
                return i - j;
            }
        }
        free(next);
        return -1;
    }
    static void compute_prefix(const char *pattern, int next[]){
        int i;
        int j = -1;
        const int m = strlen(pattern);
        next[0] = j;
        for(i = 0; i < m; ++i){
            while(j > -1 && pattern[j + 1] != pattern[i]) j = next[j];
            if(pattern[i] == pattern[j + 1]) j++;
            next[i] = j;
        }

    }
};