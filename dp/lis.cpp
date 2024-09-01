#include <bits/stdc++.h>
using namespace std;


//struct hash_pair {
//    template <class T1, class T2>
//    size_t operator()(const pair<T1, T2>& p) const
//    {
//        auto hash1 = hash<T1>{}(p.first);
//        auto hash2 = hash<T2>{}(p.second);
//
//        if (hash1 != hash2) {
//            return hash1 ^ hash2;
//        }
//
//        // If hash1 == hash2, their XOR is zero.
//          return hash1;
//    }
//};


//https://leetcode.com/problems/longest-increasing-subsequence/description/
int dp[2501];


int lis(const vector<int>& nums, int cur){ // O(n^2) time complexity, O(n) space complexity
	if(cur >= (int)nums.size())
		return 0;

	if(dp[cur] != -1)
		return dp[cur];

	dp[cur] = 0;
	for(int next = cur + 1 ; next < (int)nums.size() ; ++next){
		if(nums[next] > nums[cur])
			dp[cur] = max(dp[cur], lis(nums, next));
	}
	return ++dp[cur];
}
int lengthOfLIS(vector<int>& nums) {
	if((int)nums.size() == 1)
		return 1;

    memset(dp, -1, sizeof(dp));
    nums.insert(nums.begin(), INT_MIN);
    return lis(nums, 0) - 1;
}


int main(){
	vector<int> nums {10,9,2,5,3,7,101,18};
	cout << lengthOfLIS(nums);
	return 0;
}

