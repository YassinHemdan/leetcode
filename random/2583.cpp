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
    struct KthLargestNumber{
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        int k;
        KthLargestNumber(int k) : k(k) {}
        void add(long long num){
            if((int)minHeap.size() < k)
                minHeap.push(num);
            else if(minHeap.top() < num){
                minHeap.pop();
                minHeap.push(num);
            }
        }
        long long get(){
            if((int)minHeap.size() < k)
                return -1;
            return minHeap.top();
        }
    };
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        KthLargestNumber kth(k);
        while(!q.empty()){
            int sz = q.size();
            long long sum = 0;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            kth.add(sum);
        }
        return kth.get();
    }
};
