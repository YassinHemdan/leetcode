class Solution {
public:
    string minWindow(string& s, string& t) {
        vector<int> freq(123);
        int letters = 0;
        for(char& c : t){
            int idx = (int)c;
            freq[idx]++;
            if(freq[idx] == 1)
                letters++;
        }

        int l = 0, r = 0;
        int start = -1, len = INT_MAX;
        int completedLetters = 0;
        vector<int> completedFreq(123);
        while(l <= r && r < (int)s.size()){
            int add = (int)s[r];
            if(freq[add]){
                completedFreq[add]++;
                if(completedFreq[add] == freq[add])
                    ++completedLetters;
            }
            while(completedLetters == letters){
                if(r - l + 1 < len)
                    len = r - l + 1, start = l;
                
                int remove = (int)s[l];
                if(freq[remove]){
                    completedFreq[remove]--;
                    if(completedFreq[remove] < freq[remove])
                        completedLetters--;
                }
                ++l;
            }
            ++r;
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
