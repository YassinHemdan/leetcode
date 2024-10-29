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
private:
    TreeNode* change(TreeNode* root){
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        if(root->left)
            left = change(root->left);
        if(root->right)
            right = change(root->right);
        if(!left && !right)
            return root;
        if(left && right){
            left->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            return right;
        }
        else if(left){
            root->right = root->left, root->left = nullptr;
            return left;
        }
        return right;
    }
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        change(root);
    }
};
