class Solution {
private:
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
    bool isLetter(char c){
        return c >= 'a' && c <='z';
    }
    string repeat(string& num, string& s){
        int n = 0;
        for(char& c : num){
            int d = c - '0';
            n = n * 10 + d;
        }
        string repeated = "";
        while(n--)
            repeated += s;
        return repeated;
    }
    string extractNum(int& idx, string& s){
        string num = "";
        while(isDigit(s[idx]))
            num += s[idx++];
        return num;
    }
    string extractString(int& idx, string& s){
        string str = "";
        while(isLetter(s[idx]))
            str += s[idx++];
        return str;
    }
public:
    string decodeString(string& s) {
        stack<string> st;
        for(int i = 0 ; i<(int)s.size() ; ){
            char c = s[i];
            if(c != ']'){
                if(isLetter(c)){
                    string str = extractString(i, s);
                    string pre = "";
                    if(!st.empty() && isLetter(st.top()[0]))
                        pre = st.top(), st.pop();;
                    st.push(pre + str);
                }
                else if(isDigit(c)){
                    string str = extractNum(i, s);
                    string pre = "";
                    if(!st.empty() && isDigit(st.top()[0]))
                        pre = st.top(), st.pop();
                    st.push(pre + str); 
                }
                else
                    st.push("["), ++i;
            }
            else{
                string str = st.top();
                st.pop();
                st.pop();
                string num = st.top();
                st.pop();

                string repeated = repeat(num, str);
                string pre = "";
                if(!st.empty() && isLetter(st.top()[0]))
                    pre = st.top(), st.pop();
                st.push(pre + repeated);
                ++i;
            }
        }
        return st.top();
    }
};
