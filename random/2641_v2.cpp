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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int levelSum = root->val;

        while(!nodeQueue.empty()){
            int sz = nodeQueue.size();
            int nextLevelSum = 0;
            while(sz--){
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();

                node->val = levelSum - node->val;
                int siblingSum =
                    (node->left ? node->left->val : 0) + 
                    (node->right ? node->right->val : 0);
                
                if(node->left){
                    nextLevelSum += node->left->val;
                    node->left->val = siblingSum;
                    nodeQueue.push(node->left);
                }
                if(node->right){
                    nextLevelSum += node->right->val;
                    node->right->val = siblingSum;
                    nodeQueue.push(node->right);
                }
            }
            levelSum = nextLevelSum;
        }
        return root;
    }
};
