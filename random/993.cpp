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
    void dfs(TreeNode* root, int target, int level, int& foundLevel, int& parent){
        if(root->left && root->left->val == target){
            parent = root->val;
            foundLevel = level + 1;
            return;
        }
        if(root->right && root->right->val == target){
            parent = root->val;
            foundLevel = level + 1;
            return;
        }
        if(root->left)
            dfs(root->left, target, level + 1, foundLevel, parent);
        if(root->right)
            dfs(root->right, target, level + 1, foundLevel, parent);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int parentX = -1, parentY = -1;
        int levelX = -1, levelY = -1;

        dfs(root, x, 0, levelX, parentX);
        dfs(root, y, 0, levelY, parentY);

        if(levelX == levelY && parentX != parentY)
            return true;
        return false;
    }
};
