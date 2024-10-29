class Solution {
private:
    const static int N = 1e5 + 2;
    int nodeLevel[N];
    int nodeHeight[N];
    int firstMax[N];
    int secondMax[N];

    int height(TreeNode* root){
        int h = 0;
        if(root->left)
            h = 1 + height(root->left);
        if(root->right)
            h = max(h, 1 + height(root->right));

        nodeHeight[root->val] = h;
        return h;
    }
    void bfs(TreeNode* root){
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        for(int level = 0, sz = 1 ; !nodeQueue.empty() ; ++level, sz = nodeQueue.size()){
            int levelFirstMax = -1;
            int levelSecondMax = -1;
            while(sz--){
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();

                nodeLevel[node->val] = level;

                if(nodeHeight[node->val] > levelFirstMax)
                    levelSecondMax = levelFirstMax, levelFirstMax = nodeHeight[node->val];
                else if(nodeHeight[node->val] == levelFirstMax)
                    levelSecondMax = levelFirstMax;
                else if(nodeHeight[node->val] > levelSecondMax)
                    levelSecondMax = nodeHeight[node->val];
                
                if(node->left)
                    nodeQueue.push(node->left);
                if(node->right)
                    nodeQueue.push(node->right);
            }
            firstMax[level] = levelFirstMax;
            secondMax[level] = levelSecondMax;
        }
    }
    void clear(){
        memset(nodeHeight, 0, sizeof(nodeHeight));
        memset(nodeLevel, 0, sizeof(nodeLevel));
        memset(firstMax, -1, sizeof(nodeLevel));
        memset(secondMax, -1, sizeof(nodeLevel));
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        clear();
        height(root);
        bfs(root);
        vector<int> ans((int)queries.size());
        for(int i=0 ; i<(int)queries.size() ; ++i){
            int node = queries[i];
            int level = nodeLevel[node];
            int height = nodeHeight[node];
            int levelFirstMax = firstMax[level];
            int levelSecondMax = secondMax[level];

            if(height == levelFirstMax)
                ans[i] = levelSecondMax + level;
            else
                ans[i] = levelFirstMax + level;
        }
        return ans;
    }
};
