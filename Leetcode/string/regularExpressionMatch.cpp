#include<string>
using namespace std;
class Solution{
public:
    bool isMatching(const string& s, const string& p){
        return isMatch(s.c_str(), p.c_str());
    }
private:
    bool isMatch(const char *s, const char *p){
        if(*p == '\0') return *s == '\0';
    }
};

