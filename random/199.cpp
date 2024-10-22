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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSideNodes;
        if(root == nullptr)
            return rightSideNodes;
        
        queue<TreeNode*> q;
        q.push(root);
        for(int sz = 1 ; !q.empty() ; sz = (int)q.size()){
            rightSideNodes.push_back(q.front()->val); // the first value in each level
            while(sz--){
                TreeNode* cur_node = q.front();
                q.pop();

                if(cur_node->right != nullptr) // check for right first
                    q.push(cur_node->right);
                if(cur_node->left != nullptr)
                    q.push(cur_node->left);
            }
        }
        return rightSideNodes;
    }
};
