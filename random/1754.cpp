class Solution {
private:
    string word1, word2;
public:
    string largestMerge(const string& str1, const string& str2) {
        this->word1 = str1, this->word2 = str2;
        int n1 = word1.size(), n2 = word2.size();

        string merged = "";

        while(!word1.empty() || !word2.empty()){
            if(word1.empty()){
                for(char c : word2)
                    merged += c;
                break;
            }
            else if(word2.empty()){
                for(char c : word1)
                    merged += c;
                break;
            }
            else if(word1 > word2){
                merged += word1[0];
                word1.erase(word1.begin());
            }
            else{
                merged += word2[0];
                word2.erase(word2.begin());
            }
        }
        return merged;
    }
};
