class Solution {
private:
    int lis[1001];
    int lds[1001];
    
    int lisBackward(vector<int>& nums, int idx){
        if(idx < 0)
            return 0;
        if(lis[idx] != -1)
            return lis[idx];
        lis[idx] = 0;
        for(int pre = idx - 1 ; pre > -1 ; --pre){
            if(nums[pre] < nums[idx])
                lis[idx] = max(lis[idx], lisBackward(nums, pre));
        }
        ++lis[idx];
        return lis[idx];
    }
    int ldsForward(vector<int>& nums, int idx){
        if(idx >= (int)nums.size())
            return 0;
        if(lds[idx] != -1)
            return lds[idx];
        lds[idx] = 0;
        for(int next = idx + 1 ; next < (int)nums.size() ; ++next){
            if(nums[next] < nums[idx])
                lds[idx] = max(lds[idx], ldsForward(nums, next));
        }
        ++lds[idx];
        return lds[idx];
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        memset(lis, -1, sizeof(lis));
        memset(lds, -1, sizeof(lds));

        int maxLength = 0;
        for(int i=1 ; i<(int)nums.size() - 1 ; ++i){
            int length1 = lisBackward(nums, i);
            int length2 = ldsForward(nums, i);
            if(length1 > 1 && length2 > 1)
                maxLength = max(maxLength, length1 + length2 - 1);
        }
        return (int)nums.size() - maxLength;
    }
};
