class Solution {
private:
    char rec(const string& expression, int& idx){
        bool foundTrue = false;
        bool foundFalse = false;
        char op = expression[idx];
        idx += 2;
        while(idx < (int)expression.size() && expression[idx] != ')'){
            char c = expression[idx];
            if(c == 't')
                foundTrue = true;
            else if(c == 'f')
                foundFalse = true;
            else if(c == '&' || c == '|' || c == '!'){
                bool sub = rec(expression, idx);
                if(sub == true)
                    foundTrue = true;
                else
                    foundFalse = true;
            }
            ++idx;
        }
        if(op == '!'){
            if(foundTrue)
                return false;
            return true;
        }
        else if(op == '|'){
            if(foundTrue)
                return true;
            return false;
        }
        else{
            if(foundFalse)
                return false;
            return true;
        }
    }
public:
    bool parseBoolExpr(const string& expression) {
        int idx = 0;
        return rec(expression, idx);
    }
};
