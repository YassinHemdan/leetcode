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
struct MyPair{
    int height;
    int diameter;
    MyPair() : height(0), diameter(0){}
};
MyPair diameter(TreeNode* root){
    MyPair rootPair;
    MyPair leftPair;
    MyPair rightPair;

    if(root->left)
        leftPair = diameter(root->left), leftPair.height++;
    if(root->right)
        rightPair = diameter(root->right), rightPair.height++;

    rootPair.height = max(rightPair.height, leftPair.height);
    rootPair.diameter = max(rightPair.height + leftPair.height,
                        max(leftPair.diameter, rightPair.diameter));

    return rootPair;
}
int diameterOfBinaryTree(TreeNode* root) {
    return diameter(root).diameter;
}
};
