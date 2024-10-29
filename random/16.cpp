class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int ans = -1;
        for(int i=0 ; i<n - 2; ++i){
            int s = i + 1, e = n - 1;
            while(s < e){
                int sum = nums[i] + nums[s] + nums[e];
                int curDiff = abs(target - sum);
                if(curDiff < diff)
                    ans = sum, diff = curDiff;
                if(sum > target)
                    e--;
                else
                    s++;
            }
        }
        return ans;
    }
};
