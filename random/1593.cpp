class Solution {
private:
    unordered_set<string> hashSet;

    int backtrack(int start, const string& s){
        if(start >= (int)s.size())
            return 0;

        string substr = "";
        int maxNum = 0;
        for(int end = start ; end < (int)s.size() ; ++end){
            substr += s[end];
            if(hashSet.find(substr) == hashSet.end()){
                hashSet.insert(substr);
                maxNum = max(maxNum, 1 + backtrack(end + 1, s));
                hashSet.erase(substr);
            }
        }
        return maxNum;
    }
public:
    int maxUniqueSplit(const string& s) {
        hashSet.clear();
        return backtrack(0, s);
    }
};
