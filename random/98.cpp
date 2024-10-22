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
    bool isValid(TreeNode* root, long long mn, long long mx){
        if(root == nullptr)
            return true;
        int val = root->val;
        return val > mn && val < mx && 
               isValid(root->left, mn, val) &&
               isValid(root->right, val, mx); 
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT64_MIN, INT64_MAX);
    }
};
