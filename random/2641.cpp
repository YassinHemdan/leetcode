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
        queue<pair<TreeNode*, TreeNode*>> q;
        TreeNode* temp = new TreeNode(root->val);
        q.push({temp, root});
        unordered_map<TreeNode*, int> mp;
        mp[temp] = root->val;
        int levelSum = root->val;

        while(!q.empty()){
            int sz = q.size();
            int newLevelSum = 0;
            while(sz--){
                TreeNode* parent = q.front().first;
                TreeNode* child = q.front().second;
                q.pop();

                child->val = levelSum - mp[parent];
                if(child->left){
                    q.push({child, child->left});
                    mp[child] += child->left->val;
                    newLevelSum += child->left->val;
                }
                if(child->right){
                    q.push({child, child->right});
                    mp[child] += child->right->val;
                    newLevelSum += child->right->val;
                }
            }
            levelSum = newLevelSum;
        }
        delete temp;
        return root;
    }
};
