class Solution {
public:
    long long dividePlayers(const vector<int>& skill) {
        int n = skill.size();
        int teams = n / 2;
        int sum = 0;

        unordered_map<int, int> skills;
        for(const int& val : skill)
            sum += val, skills[val]++;
        
        if(sum % teams != 0)
            return -1;
        
        int teamSkill = sum / teams;
        int matched = 0;
        long long chemistry = 0;
        for(const int& val : skill){
            int player1 = val;
            int s1 = --skills[player1];

            int player2 = teamSkill - val;
            int s2 = --skills[player2];

            if(s1 < 0 || s2 < 0)
                continue;
            ++matched;
            chemistry += (long long) player1 * (long long)player2;
        }
        return matched == teams ? chemistry : -1;
    }
};
