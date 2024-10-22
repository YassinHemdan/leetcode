class Solution {
public:
    int numberOfSubstrings(const string& s, int k) {
        int count = 0;
        int n = s.size();
        for(int i=0 ; i<n ; ++i){
            bool found = false;
            unordered_map<char, int> freq;
            for(int j=i ; j<n ; ++j){
                char c = s[j];
                freq[c]++;
                if(freq[c] >= k)
                    found = true;
                if(found)
                    ++count;
            }
        }
        return count;
    }
};
