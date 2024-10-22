class Solution {
public:
    vector<string> stringSequence(const string& target) {
        vector<string> strs;
        string str = "";
        for(char c : target){
            char t = 'a';
            str += t;
            strs.push_back(str);
            while(t != c){
                int n = str.size();
                if(t == 'z')
                    t = 'a';
                else
                    ++t;
                str[n - 1] = t;
                strs.push_back(str);
            }
        }
        return strs;
    }
};
