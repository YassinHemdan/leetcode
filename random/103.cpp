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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> levels;
        deque<TreeNode*> nodeQueue;
        nodeQueue.push_front(root);
        bool f = true;
        while(!nodeQueue.empty()){
            int sz = nodeQueue.size();
            vector<int> level;
            while(sz--){
                if(f){
                    TreeNode* node = nodeQueue.front();
                    nodeQueue.pop_front();
                    level.push_back(node->val);
                    if(node->left)
                        nodeQueue.push_back(node->left);
                    if(node->right)
                        nodeQueue.push_back(node->right);
                }
                else{
                    TreeNode* node = nodeQueue.back();
                    nodeQueue.pop_back();
                    level.push_back(node->val);
                    if(node->right)
                        nodeQueue.push_front(node->right);
                    if(node->left)
                        nodeQueue.push_front(node->left);
                }
            }
            levels.push_back(level);
            f = !f;
        }
        return levels;
    }
};
