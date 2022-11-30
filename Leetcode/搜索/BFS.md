### BFS

Leetcode 127.单词接龙

#### 双向BFS

```c++
beginWord = "hit";
endWord = "cog";
wordList = ["hot", "dot","dog","lot","log", "cog"];
```

- 一端从hit开始搜索，找到所有和hit相邻的单词，即只差一个字符的单词，并且都存入队列queue中。
- 另一端从cog开始搜索，找到所有和cog相邻的单词，并且都存入queue2中

当某个单词，同时被两个队列都访问过，那么说明找到了一条路径。同时也是最短的路径

