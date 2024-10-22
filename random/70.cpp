class Solution {
public:
int memo[46];
int climb(int n){
    if(n < 0)
        return 0;
    if(memo[n] != -1)
        return memo[n];
    if(n == 0)
        return 1;
    
    return memo[n] = climb(n - 1) + climb(n - 2);
}
int climbStairs(int n) {
    memset(memo, -1, sizeof(memo));
    return climb(n);
}
};
