//BFS search
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
class Solution
{
private:
    /* data */
public:
    int ladderLength(std::string beginWord,std::string endWord,std::vector<std::string>&wordList)
    {
        wordList.push_back(beginWord);
        std::queue<std::string> queue1;
        queue1.push(beginWord);
        std::queue<std::string> queue2;
        queue2.push(endWord);
        std::unordered_set<std::string> visited1;
        visited1.insert(beginWord);
        std::unordered_set<std::string> visited2;
        visited2.insert(endWord);
        std::unordered_set<std::string> wordListSet(wordList.begin(),wordList.end(),wordList.size());
        int count = 0;
        if (wordListSet.find(endWord)==wordListSet.end())
        {
            /* code */
            return count;
        }
        while (!queue1.empty()&&!queue2.empty())
        {
            /* code */
            ++count;//每增加一层就增加一个
            if (queue1.size()>queue2.size())
            {
                /* code */
                //总是确保queue小，从小的一端遍历
                queue1.swap(queue2);
                visited1.swap(visited2);
            }
            int length = queue1.size();
            while (length--)
            {
                /* code */
                std::string str = queue1.front();
                queue1.pop();
                for (int i = 0; i < str.length(); ++i)
                {
                    /* code */
                    char ch = str[i];
                    for (char c = 'a'; c<='z'; ++c)
                    {
                        /* code */
                        str[i]=c;
                        if (visited1.find(str)!=visited1.end())
                        {
                            /* code */
                            continue;

                        }
                        if (visited2.find(str)!= visited2.end())
                        {
                            /* code */
                            return count+1;
                        }
                        if (wordListSet.find(str)!= wordListSet.end())
                        {
                            /* code */
                            queue1.push(str);
                            visited1.insert(str);

                        }
                    }
                    str[i]=ch;
                }
            }         
        }
        return 0;
    }
    
};

