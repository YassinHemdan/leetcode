class Solution {
private:
    int dp[1001][3001][4];
    int F = 0;
    int W = 1;
    int E = 2;
    int mod = 1e9 + 7;
    int nextScore(char c1, char c2, int score){
        if(c1 == c2)
            return score;
        if(c1 == 'F' && c2 == 'E')
            return score - 1;
        if(c1 == 'W' && c2 == 'F')
            return score - 1;
        if(c1 == 'E' && c2 == 'W')
            return score - 1;
        else
            return score + 1;

    }
    int count(const string& s, int idx, int monster = 3, int score = 2000){
        if(idx >= (int)s.size())
            return score - 2000 > 0;
        if(dp[idx][score][monster] != -1)
            return dp[idx][score][monster];
        dp[idx][score][monster] = 0;

        if(monster != F){
            dp[idx][score][monster] += count(s, idx + 1, F, nextScore(s[idx], 'F', score));
            dp[idx][score][monster] %= mod;
        }
        if(monster != W){
            dp[idx][score][monster] += count(s, idx + 1, W, nextScore(s[idx], 'W', score));
            dp[idx][score][monster] %= mod;
        }
        if(monster != E){
            dp[idx][score][monster] += count(s, idx + 1, E, nextScore(s[idx], 'E', score));
            dp[idx][score][monster] %= mod;
        }
        
        return dp[idx][score][monster];
    }
public:
    int countWinningSequences(const string& s) {
        memset(dp, -1, sizeof(dp));
        return count(s, 0);
    }
};
