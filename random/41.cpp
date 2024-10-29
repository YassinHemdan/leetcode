class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0 ; i<n ; ++i)
            if(nums[i] < 0)
                nums[i] = 0;
        
        for(int i=0 ; i<n ; ++i){
            int val = abs(nums[i]);
            int idx = val - 1;
            if(idx < 0 || idx >= n)
                continue;
            if(nums[idx] > 0)
                nums[idx] *= -1;
            else if(nums[idx] == 0)
                nums[idx] = -(n + 1);
        }
        for(int i=1 ; i<=n ; ++i){
            if(nums[i - 1] >= 0)
                return i;
        }
        return n + 1;
    }
};
