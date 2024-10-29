class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = (int)prizePositions.size();
        vector<int> lastIdx(n), rightMax(n + 1);

        int s = 0, e = 0;
        while(s <= e && s != n){
            if(e == n){
                lastIdx[s] = e;
                rightMax[s] = e - s;
                ++s;
            }
            else if(prizePositions[e] - prizePositions[s] <= k)
                ++e;
            else{
                lastIdx[s] = e;
                rightMax[s] = e - s;
                ++s;
            }
        }
        for(int i = n - 2 ; i > -1 ; --i)
            rightMax[i] = max(rightMax[i], rightMax[i + 1]);
        
        int maxSum = 0;
        for(int i=0 ; i<n ; ++i)
                maxSum = max(maxSum, lastIdx[i] - i + rightMax[lastIdx[i]]);
        return maxSum;
    }
};
