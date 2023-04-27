#include<vector>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
//中序遍历
class Solution{
public:
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> result;
        stack<const TreeNode*> s;
        const TreeNode* p = root;
        while(!s.empty() || p != nullptr){
            if(p != nullptr){
                s.push(p);
                p = p->left;
            }
            else{
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
};

class Solution1{
public:
    vector<int> inorderTraversal(TreeNode* root){
        
    }
};