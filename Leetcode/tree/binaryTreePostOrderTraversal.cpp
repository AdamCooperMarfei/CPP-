#include<stack>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};
//后序遍历
class Solution{
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        stack<const TreeNode*> s;
        const TreeNode* p = root, * q = nullptr;
        do{
            while(p != nullptr){
                s.push(p);
                p = p->left;
            }
            q = nullptr;
            while(!s.empty()){
                p = s.top();
                s.pop();
                if(p->right == q){
                    result.push_back(p->val);
                    q = p;
                }
                else{
                    s.push(p);
                    p = p->right;
                    break;
                }
            }
        }while(! s.empty());
    }
};
