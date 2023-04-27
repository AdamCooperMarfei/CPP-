#include<string>
#include<unordered_map>
using namespace std;
typedef string::const_iterator Iterator;
namespace std{
template<>
struct hash<pair<Iterator, Iterator>>{
    size_t operator()(pair<Iterator, Iterator> const &p) const{
        return ((size_t) &(*p.first))^((size_t) &(*p.second));
    }
};
}
class Solution1{
public:
    string longestPalindromie(string const &s){
        cache.clear();
        return cachedLongestPalindromie(s.begin(), s.end());
    }
private:
    unordered_map<pair<Iterator, Iterator>, string> cache;
    string longestPalindromie(Iterator first, Iterator last){
        size_t length = distance(first, last);
        if(length < 2) return string(first, last);
        auto s = cachedLongestPalindromie(next(first), prev(last));
        if(s.length() == length - 2 && *first == *prev(last))
            return string(first, last);
        auto s1 = cachedLongestPalindromie(next(first), last);
        auto s2 = cachedLongestPalindromie(first, prev(last));
        if(s.size() > s1.size()) return s.size() > s2.size()? s : s2;
        else return s1.size() > s2.size()? s1: s2;
    }
    string cachedLongestPalindromie(Iterator first, Iterator last){
        auto key = make_pair(first, last);
        auto pos = cache.find(key);
        if(pos != cache.end()) return pos->second;
        else return cache[key] = longestPalindromie(first, last);
    }
};