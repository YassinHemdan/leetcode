class Solution {
private:
    int idx(char c){
        if(c == 'c')
            return 0;
        if(c == 'r')
            return 1;
        if(c == 'o')
            return 2;
        if(c == 'a')
            return 3;
        return 4;
    }
    bool isValidCombination(const vector<int>& croak){
        for(int i=0 ; i<4 ; ++i)
            if(croak[i] > 0)
                return false;
        return true;
    } 
public:
    int minNumberOfFrogs(const string& croakOfFrogs) {
        vector<int> croak(5);
        int minFrogs = 0;
        int completed = 0;
        for(char c : croakOfFrogs){
            int cur = idx(c);
            if(c == 'c'){
                croak[cur]++;
                if(!completed)
                    ++minFrogs;
                else
                    --completed;
            }
            else{
                int prev = idx(c) - 1;
                if(croak[prev] != 0){
                    croak[prev]--;
                    croak[cur]++;
                }
                else
                    return -1;
                if(c == 'k'){
                    ++completed;
                }
            }
        }
        return isValidCombination(croak) ? minFrogs : -1;
    }
};
