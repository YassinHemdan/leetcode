// subset sum problem

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


// N <= 500, M <= 2000 .. M = target
// value[i] <= 10^8

int dp[501][2001];

bool pick_or_leave(const vector<int>& nums, int remain, int idx){ // O(NM) time and space complexity
	if(remain == 0)
		return true;
	if(idx >= (int)nums.size())
		return false;
	if(dp[idx][remain] != -1)
		return dp[idx][remain];

	int leave = pick_or_leave(nums, remain, idx + 1);
	int pick = 0;

	if(remain - nums[idx] >= 0)
		pick = pick_or_leave(nums, remain - nums[idx], idx + 1);

	return dp[idx][remain] = (pick || leave);
}
bool subset_sum(const vector<int>& nums, int target){
	memset(dp, -1, sizeof(dp));
	return pick_or_leave(nums, target, 0);
}

int main(){
	vector<int> nums {3,12,4,12,5,2};
	cout << subset_sum(nums, 13);
	return 0;
}

