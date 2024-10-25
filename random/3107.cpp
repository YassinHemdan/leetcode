class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = n / 2;
        long long count = 0;

        if(nums[mid] == k)
            return count;
        
        count += abs(nums[mid] - k);
        nums[mid] = k;
        
        for(int i=mid+1 ; i<n ; ++i){
            if(nums[i] >= nums[i - 1])
                break;
            count += abs(nums[i] - k);
            nums[i] = k;
        }
        for(int i=mid-1 ; i>-1 ; --i){
            if(nums[i] <= nums[i + 1])
                break;
            count += abs(nums[i] - k);
            nums[i] = k;
        }
        return count;
    }
};
