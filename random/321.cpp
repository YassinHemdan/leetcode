static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
private:
    int getPriority(vector<int>& nums1, vector<int>& nums2,
                    int idx1, int idx2, int n1, int n2){
        
        while(idx1 < n1 && idx2 < n2 && nums1[idx1] == nums2[idx2])
            ++idx1, ++idx2;
        
        if(nums1[idx1] > nums2[idx2])
            return 1;
        return 2;
    }
    void largestMerge(vector<int>& merged, vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int idx1 = 0, idx2 = 0;

        nums1.push_back(-1);
        nums2.push_back(-1);

        while((int)merged.size() < n1 + n2){
            int priority = getPriority(nums1, nums2, idx1, idx2, n1, n2);
            if(priority == 1)
                merged.push_back(nums1[idx1++]);
            else
                merged.push_back(nums2[idx2++]);
        }
    }
    void getMaxLex(vector<int>& ans, const vector<int>& nums, int k){
        if(k == 0)
            return;
        if(k >= (int)nums.size()){
            ans = nums;
            return;
        }
        int n = nums.size();
        for(int i=0 ; i<n ; ++i){
            int remaining = k - (int)ans.size();
            if(remaining == 0 && nums[i] <= ans.back())
                continue;
            while(!ans.empty() && remaining + 1 <= n - i && nums[i] > ans.back())
                ++remaining, ans.pop_back();
            ans.push_back(nums[i]);
        }
    }
public:
    vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2, int k) {
        vector<int> maxLex {0};
        int n1 = nums1.size(), n2 = nums2.size();

        for(int i=0 ; i<=k ; ++i){
            vector<int> maxLex1, maxLex2;
            getMaxLex(maxLex1, nums1, i);
            getMaxLex(maxLex2, nums2, k - i);

            if((int)maxLex1.size() + (int)maxLex2.size() < k)
                continue;
            
            vector<int> merged;
            largestMerge(merged, maxLex1,  maxLex2);
            maxLex = max(maxLex, merged);
        }
        return maxLex;
    }
};
