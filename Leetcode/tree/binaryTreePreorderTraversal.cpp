#include<vector>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
//前序遍历
class Solution{
public:
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> result;
        stack<const TreeNode*> s;
        if(root != nullptr) s.push(root);
        while(!s.empty()){
            const TreeNode* p = s.top();
            s.pop();
            result.push_back(p->val);
            if(p->right != nullptr) s.push(p->right);
            if(p->left != nullptr) s.push(p->left);
        }
        return result;
    }
};

class Solution1{
public:
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> result;
        TreeNode *cur = root, *prev = nullptr;
        while(cur != nullptr){
            if(cur->left == nullptr){
                result.push_back(cur->val);
                prev = cur;
                cur = cur->right;
            }
            else{
                TreeNode *node = cur->left;
                while(node->right != nullptr && node->right != cur){
                    node = node->right;
                }
                if(node->right == nullptr){
                    result.push_back(cur->val);
                    node->right = cur;
                    prev = cur;
                    cur = cur->left;
                }
                else{
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};