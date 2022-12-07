- 172.Factorial Trailing Zeros:判断一个数的阶乘含0的个数
- 思路：阶乘的结果最后含有0的个数只与5的阶乘有关，所以只需计算数能分解出多少各5的阶乘

```c++
class Solution
{
    public:
    int trailingZeroes(int n)
    {
        return (n>5?n/5+trailingZeroes(n/5):0);        
    }
};
```

------

- 79.Word Search
- 思路：DFS

```c++
class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if(board.size()==0) return false;
        h = board.size();
        w = board[0].size();
        for(int i=0;i<w;i++)
            for(int j=0;j<h;j++)
                if(search(board, word, 0, i, j)) return true;
        return false;
    }
    
    bool search(vector<vector<char>> &board, 
             const string& word, int d, int x, int y) {
        if(x<0 || x==w || y<0 || y==h || word[d] != board[y][x]) 
            return false;
        
        // Found the last char of the word
        if(d==word.length()-1)
            return true;
        
        char cur = board[y][x];
        board[y][x] = 0; 
        bool found = search(board, word, d+1, x+1, y)
                  || search(board, word, d+1, x-1, y)
                  || search(board, word, d+1, x, y+1)
                  || search(board, word, d+1, x, y-1);
        board[y][x] = cur;
        return found;
    }
private:
    int w;
    int h;
};
```

------

- 100.Same Tree

```c++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both are emtry: same
        if (!p && !q) return true;
        // One is emtry: not the Same
        if (!p || !q) return false;
        // Both are not emptry, compare the root value
        if (p->val != q->val) return false;
        // Compare left-subtree and right-subtree recursively.
        return isSameTree(p->left, q->left) 
            && isSameTree(p->right, q->right); 
    }
};
```

------

- 150.Evaluate Reverse Polish Notation
- 思路：两个栈

```c++
class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (const string& token : tokens) {
      if (isdigit(token.back())) {
        s.push(stoi(token));
      } else {
        int n2 = s.top(); s.pop();
        int n1 = s.top(); s.pop();        
        int n = 0;
        switch (token[0]) {
          case '+': n = n1 + n2; break;
          case '-': n = n1 - n2; break;
          case '*': n = n1 * n2; break;
          case '/': n = n1 / n2; break;
        }
        s.push(n);
      }
    }
    return s.top();
  }
};
```

------

- 282.Expression Add Operators

```c++
// Author: Huahua
// Running time: 128 ms (<79.97%)
class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    dfs(num, target, 0, "", 0, 0, &ans);
    return ans;
  }
private:
  void dfs(const string& num, const int target,  // input
           int pos, const string& exp, long prev, long curr, // state
           vector<string>* ans) {  // output
    if (pos == num.length()) {
      if (curr == target) ans->push_back(exp);
      return;
    }
    
    for (int l = 1; l <= num.size() - pos; ++l) {
      string t = num.substr(pos, l);    
      if (t[0] == '0' && t.length() > 1) break; // 0X...
      long n = std::stol(t);
      if (n > INT_MAX) break;
      if (pos == 0) {
        dfs(num, target, l, t, n, n, ans);
        continue;
      }
      dfs(num, target, pos + l, exp + '+' + t, n, curr + n, ans);
      dfs(num, target, pos + l, exp + '-' + t, -n, curr - n, ans);
      dfs(num, target, pos + l, exp + '*' + t, prev * n, curr - prev + prev * n, ans);
    }    
  }
};
```

<font color="#ff0000">code：花花酱 YouTube</font>