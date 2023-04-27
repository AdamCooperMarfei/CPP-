#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    vector<vector<int>> zigzagLevalTraversal(TreeNode* root){
        vector<vector<int>> result;
        traverse(root, 1, result, true);
        return result;
    }
    void traverse(TreeNode* root, size_t level, vector<vector<int>> &result, bool left_to_right){
        if(!root) return;
        if(level > result.size()) result.push_back(vector<int>());
        if(left_to_right) 
            result[level - 1].push_back(root->val);
        else
            result[level - 1].insert(result[level - 1].begin(), root->val);
        traverse(root->left, level + 1, result, !left_to_right);
        traverse(root->right, level + 1, result, !left_to_right);
    }
};

class Solution1{
public:
    vector<vector<int>> zigzagLevelTraversal(TreeNode* root){
        vector<vector<int>> result;
        queue<TreeNode*> current, next;
        bool left_to_right = true;
        if(root == nullptr)
            return result;
        else
            current.push(root);
        while(!current.empty()){
            vector<int> level;
            while(!current.empty()){
                TreeNode* node = current.front();
                current.pop();
                level.push_back(node->val);
                if(node->left != nullptr) next.push(node->left);
                if(node->right != nullptr) next.push(node->right);
            }
            if(!left_to_right) reverse(level.begin(), level.end());
            result.push_back(level);
            left_to_right = !left_to_right;
            swap(next, current);
        }
        return result;
    }
};