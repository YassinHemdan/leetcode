class Solution {
public:
    long long minimumSteps(const string& s) {
        long long steps = 0;
        int idx = 0;
        while(s[idx] == '0')
            ++idx;
        for(int i=idx + 1 ; i<(int)s.size() ; ++i){
            if(s[i] == '0'){
                steps += i - idx;
                ++idx;
            }
        }
        return steps;
    }
};
