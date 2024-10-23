class Solution {
public:
    bool winnerOfGame(const string& colors) {
        int a = 0;
        int b = 0;

        for(int i=1 ; i<(int)colors.size() - 1 ; ++i){
            if(colors[i] == colors[i - 1] && colors[i] == colors[i + 1]){
                a += colors[i] == 'A';
                b += colors[i] == 'B';
            }
        }
        return a > b;
    }
};
