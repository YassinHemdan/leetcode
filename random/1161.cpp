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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int maxLevelSum = INT_MIN;
        int minLevel = INT_MAX;

        for(int level = 1, sz = 1; !nodeQueue.empty(); ++level, sz = (int)nodeQueue.size()){
            int levelSum = 0;
            while(sz--){
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                levelSum += node->val;

                if(node->left)
                    nodeQueue.push(node->left);
                if(node->right)
                    nodeQueue.push(node->right);
            }
            if(levelSum > maxLevelSum)
                minLevel = level, maxLevelSum = levelSum;
        }
        return minLevel;
    }
};
