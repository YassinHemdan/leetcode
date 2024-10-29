class Solution {
private:
    void fix(bool lastLine, int remaining, vector<string>& lineStrings){
        string line = "";
        if(lastLine || (int)lineStrings.size() == 1){
            while(remaining--){
                lineStrings.back() += " ";
            }
        }
        else{
            while(remaining){
                for(string& str : lineStrings){
                    if(remaining == 0)
                        break;
                    if(str[0] == ' ')
                        str += " ", remaining--;
                }
            }
        }
    }
    string getLine(vector<string>& lineStrings){
        string line = "";
        for(string& str : lineStrings)
            line += str;
        return line;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int curLength = 0;
        vector<string> lineStrings;
        for(int i=0 ; ; ){
            int space = !lineStrings.empty();
            if(i<(int)words.size() && curLength + (int)words[i].size() + space <= maxWidth){
                curLength += (int)words[i].size() + space;
                if(!lineStrings.empty())
                    lineStrings.push_back(" ");
                lineStrings.push_back(words[i]);
                ++i;
            }
            else{
                if(curLength == maxWidth){
                    curLength = 0;
                    ans.push_back(getLine(lineStrings));
                }
                else{
                    int remain = maxWidth - curLength;
                    fix(i == (int)words.size(), remain, lineStrings);
                    ans.push_back(getLine(lineStrings));
                    curLength = 0;
                }
                if(i == (int)words.size())
                    break;
                lineStrings.clear();
            }
        }
        return ans;
    }
};
