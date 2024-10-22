class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	
	int n = (int)nums.size();
    vector<vector<int>> triples;
    
    for(int i=0 ; i<n; ++i){
    	while(i != 0 && i<n && nums[i] == nums[i - 1])
            ++i;
    	int r = i + 1;
    	int l = n - 1;
    	
    	while(r < n && r < l){
    		int cur_sum = nums[r] + nums[l];
    		if(cur_sum == -nums[i]){
    			triples.push_back({nums[r], nums[l], nums[i]});
                ++r, --l;
    	    	while(r < n && nums[r] == nums[r - 1]) // Duplicate answers.
    	    		++r;
    	    	while(l > -1 && nums[l] == nums[l + 1]) // Duplicate answers.
    	    		--l;
                continue;
    		}
    		if(cur_sum > -nums[i])
    			--l;
    		else
    			++r;
    	}
    }
    return triples;
}
};
