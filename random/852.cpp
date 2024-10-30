class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int peakIdx = -1;
        int s = 1, e = (int)nums.size() - 2;
        while(s <= e){
            peakIdx = s + (e - s) / 2;
            if(nums[peakIdx] >= nums[peakIdx - 1] && nums[peakIdx] >= nums[peakIdx + 1])
                break;
            else if(nums[peakIdx - 1] > nums[peakIdx])
                e = peakIdx - 1;
            else
                s = peakIdx + 1;
        }
        return peakIdx;
    }
};
