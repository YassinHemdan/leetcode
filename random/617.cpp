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
auto init = []() {cin.tie(0); ios::sync_with_stdio(0); return 1;}();
class Solution {
private:
    TreeNode* createNode(TreeNode* root1, TreeNode* root2){
        TreeNode* head = nullptr;
        if(root1 && root2){
            head = new TreeNode(root1->val + root2->val);
            head->left = createNode(root1->left, root2->left);
            head->right = createNode(root1->right, root2->right);
        }
        else if(root1)
            head = root1;
        else
            head = root2;
        return head;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return createNode(root1, root2);
    }
};
