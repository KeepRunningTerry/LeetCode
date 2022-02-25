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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        
        stack<TreeNode*> stack;
        stack.push(root->left);
        stack.push(root->right);

        TreeNode* node1 = new TreeNode(0);
        TreeNode* node2 = new TreeNode(0);

        while(!stack.empty()){
            node1 = stack.top();
            stack.pop();
            node2 = stack.top();
            stack.pop();
            if(node1 == nullptr && node2 == nullptr){
                continue;
            }
            if(node1 == nullptr || node2 == nullptr){
                return false;;
            }
            if(node1->val != node2->val){
                return false;
            }
            stack.push(node1->left);
            stack.push(node2->right);
            stack.push(node1->right);
            stack.push(node2->left);
        }
        return true;
    }
};