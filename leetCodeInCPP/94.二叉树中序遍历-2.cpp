/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stack;
        while(root != nullptr || !stack.empty()){
            while(root!=nullptr){
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();
            ret.push_back(root->val);
            root = root->right;
        }
        
        return ret;
    }

    vector<int> inorder(TreeNode* node, vector<int> &ret){
        if(!node){
            return ret;
        }

        inorder(node->left, ret);
        ret.push_back(node->val);
        inorder(node->right, ret);

        return ret;
    }
};