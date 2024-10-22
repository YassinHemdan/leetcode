class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> quadruplets;
	int n = (int)nums.size();
	
	if(n < 4)
		return quadruplets;
	
	sort(nums.begin(), nums.end());
	
	for(int i=0 ; i<n - 3 ; ++i){
		while(i !=0 && i<n - 3 && nums[i] == nums[i - 1])
			++i;
        bool skip = false;
		for(int j=i+1 ; j<n - 2 ; ++j){
			while(j<n - 2 && skip && nums[j] == nums[j - 1])
				++j;
			int l = j + 1;
			int r = n - 1;
			while(l < r && l < n - 1){
				long long sum = (long long)nums[i] + (long long)nums[j] + 
								(long long)nums[l] + (long long)nums[r];
				if(sum == target){
					quadruplets.push_back({nums[i], nums[j], nums[l], nums[r]});
					++l, --r;
					while(l < n - 1 && nums[l] == nums[l - 1])
						++l;
					while(r > -1 && nums[r] == nums[r + 1])
						--r;
				}
				else if(sum > target)
					--r;
				else
					++l;
			}
            skip = true;
		}
	}
	return quadruplets;
}
};
