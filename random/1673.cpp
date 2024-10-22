class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int n = nums.size();
        for(int i=0 ; i<n ; ++i){
            int remaining = k - (int)st.size();
            if(remaining == 0 && nums[i] >= st.top())
                continue;
            while(!st.empty() && remaining + 1 <= n - i && nums[i] < st.top())
                st.pop(), ++remaining;
            st.push(nums[i]);
        }
        vector<int> ans(k);
        while(k)
            ans[--k] = st.top(), st.pop();
        return ans;
    }
};
