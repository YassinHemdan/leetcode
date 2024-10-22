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
    void traverse(TreeNode* root, int num, int& sum){
        if(!root)
            return;
        num = num * 10 + root->val;
        if(!root->left && !root->right){
            sum += num;
            return;
        }
        traverse(root->left, num, sum);
        traverse(root->right, num, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        traverse(root, 0, sum);
        return sum;
    }
};
