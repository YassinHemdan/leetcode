class Solution {
public:
int maxProduct(const vector<int>& nums) {
    int mx = 1, mn = 1;
    int product = *max_element(nums.begin(), nums.end());
    for(int val : nums){
        if(val == 0){
            mx = 1, mn = 1;
            continue;
        }
        int c1 = val * mx;
        int c2 = val * mn;
        mx = max(c1, max(c2, val));
        mn = min(c1, min(c2, val));
        product = max(product, mx);
    }
    return product;
}
};
