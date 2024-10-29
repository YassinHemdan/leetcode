class Solution {
private:
    multiset<pair<pair<int, int>, int>> st;
    int minCol = 0;
    int maxCol = 0;
    void traverse(int i, int j, TreeNode* root){
        minCol = min(minCol, j);
        maxCol = max(maxCol, j);
        st.insert({{i, j}, root->val});
        if(root->left)
            traverse(i + 1, j - 1, root->left);
        if(root->right)
            traverse(i + 1, j + 1, root->right);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        maxCol = 0;
        minCol = 0;
        st.clear();
        traverse(0, 0, root);

        if(minCol < 0)
            minCol *= -1;
        
        vector<vector<int>> ans(maxCol + minCol + 1);

        while(!st.empty()){
            auto p = *st.begin();
            st.erase(st.begin());

            int idx = p.first.second + minCol;
            int value = p.second;
            ans[idx].push_back(value);
        }
        return ans;
    }
};
