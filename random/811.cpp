class Solution {
private:
    string toStr(int num){
        string ans = "";
        while(num){
            int d = num % 10;
            num /= 10;
            ans += (d + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int toInt(string& str){
        int visits = 0;
        for(int i=0 ; str[i] != ' ' ; ++i)
            visits = visits * 10 + (str[i] - '0');
        return visits;
    }
    void split(unordered_map<string, int>& domainVisits, string& domain){
        int visits = toInt(domain);
        int n = domain.size();
        
        string sub = "";
        string pre = "";
        for(int i=n-1 ; true ; --i){
            if(domain[i] == ' ' || domain[i] == '.'){
                reverse(sub.begin(), sub.end());
                sub = sub + pre;
                domainVisits[sub] += visits;
                pre = "." + sub;
                sub = "";
            }
            else
                sub += domain[i];
            if(domain[i] == ' ')
                break;
        }
    }
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domainVisits;
        for(string& str : cpdomains){
            split(domainVisits, str);
        }
        vector<string> ans;
        for(auto& p : domainVisits){
            ans.push_back(toStr(p.second) + " " + p.first);
        }
        return ans;
    }
};
