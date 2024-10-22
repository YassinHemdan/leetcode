class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1;
        int idx2 = n - 1;
        int fill = m + n - 1;

        while(idx1 > -1 || idx2 > -1){
            while(idx1 < 0 && idx2 > -1)
                nums1[fill--] = nums2[idx2--];
            while(idx2 < 0 && idx1 > -1)
                nums1[fill--] = nums1[idx1--];
            
            if(idx1 > -1 && idx2 > -1){
                if(nums1[idx1] >= nums2[idx2])
                    nums1[fill--] = nums1[idx1--];
                else
                    nums1[fill--] = nums2[idx2--];
            }
        }
    }
};
