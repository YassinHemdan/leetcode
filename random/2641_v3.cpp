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
    int levelSum[100001];
    void calculateLevelSum(TreeNode* root, int level = 0){
        levelSum[level] += root->val;
        if(root->left)
            calculateLevelSum(root->left, level + 1);
        if(root->right)
            calculateLevelSum(root->right, level + 1);
    }
    void replaceNodeValue(TreeNode* root, int level = 0){
        root->val = levelSum[level] - root->val;

        int siblingSum =
            (root->right ? root->right->val : 0) + 
            (root->left ? root->left->val : 0);
        if(root->left){
            root->left->val = siblingSum;
            replaceNodeValue(root->left, level + 1);
        }
        if(root->right){
            root->right->val = siblingSum;
            replaceNodeValue(root->right, level + 1);
        }
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        memset(levelSum, 0, sizeof(levelSum));

        calculateLevelSum(root);
        replaceNodeValue(root);

        return root;
    }
};
