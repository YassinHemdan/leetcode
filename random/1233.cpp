class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        set<string> st;
        vector<string> ans;
        for(string& str : folder){
            string sub = "";
            bool found = false;
            for(int  i=0 ; i<(int)str.size() ; ++i){
                if(str[i] == '/' && i != 0){
                    if(st.find(sub) != st.end()){
                        found = true;
                        break;
                    }
                }
                sub += str[i];
            }
            if(!found){
                st.insert(str);
                ans.push_back(str);
            }
        }
        return ans;
    }
};
