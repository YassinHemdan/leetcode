class Solution {
private:
    int numOfDigits(int num){
        int count = 0;
        while(num){
            ++count;
            num = num / 10;
        }
        return count;
    }
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int repeated = 1;
        chars.push_back(' ');
        for(int i=1 ; i<(int)chars.size() ; ++i){
            if(chars[i] == chars[i - 1])
                ++repeated;
            else{
                int numLength = numOfDigits(repeated);
                chars[idx] = chars[i - 1];
                if(repeated == 1)
                    idx++;
                else{
                    for(int j = idx + numLength ; j > idx ; --j){
                        int d = repeated % 10;
                        repeated /= 10;
                        chars[j] = (char)(d + '0');
                    }
                    idx += numLength + 1;
                    repeated = 1;
                }

            }
            if(i == (int)chars.size() - 1)
                break;
        }
        while((int)chars.size() > idx)
            chars.pop_back();
        return idx;
    }
};
