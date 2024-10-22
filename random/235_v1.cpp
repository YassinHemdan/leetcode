/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
void getPath(vector<TreeNode*>& path,TreeNode* root, TreeNode* node){ 
    path.push_back(root);
    if(node->val == root->val)
        return;
    if(node->val < root->val)
        getPath(path, root->left, node);
    else
        getPath(path, root->right, node);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // // O(logn)
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;

    getPath(path1, root, p); // O(logn)
    getPath(path2, root, q); // O(logn)

    int size1 = path1.size(), size2 = path2.size();
    int minSize = min(size1, size2);
    int i=0;
    while(i < minSize && path1[i]->val == path2[i]->val) // O(logn)
        ++i;
    return path1[i - 1];
}
};
