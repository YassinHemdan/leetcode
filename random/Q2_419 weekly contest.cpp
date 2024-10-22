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
    vector<int> nodes;
    pair<int, bool> isPerfect(TreeNode* root){
        
        int cnt = 1;
        bool perfect = false;

        pair<int, bool> left {0, true};
        pair<int, bool> right {0, true};

        if(root->left)
            left = isPerfect(root->left);
        if(root->right)
            right = isPerfect(root->right);
        
        cnt += left.first + right.first;
        perfect = (left.first == right.first && right.second && left.second);

        if(perfect)
            nodes.push_back(cnt);
        
        return {cnt, perfect};
    }
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        nodes.clear();
        isPerfect(root);

        sort(nodes.rbegin(), nodes.rend());
        if(k > nodes.size())
            return -1;
        return nodes[k - 1];
    }
};
