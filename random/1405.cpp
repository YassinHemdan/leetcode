class Solution {
private:
vector<pair<int, char>> getCharacterFreq(int a, int b, int c){
    vector<pair<int, char>> letters = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
    sort(letters.rbegin(), letters.rend());

    return letters;
}

bool getLetter(const vector<pair<int, char>>& letters, pair<int, char>& letter, char c1, char c2){
    if((letters[0].first > 0) && !(c1 == c2 && c1 == letters[0].second)){
        letter = letters[0];
        return true;
    }
    if((letters[1].first > 0) && !(c1 == c2 && c1 == letters[1].second)){
        letter = letters[1];
        return true;
    }
    if((letters[2].first > 0) && !(c1 == c2 && c1 == letters[2].second)){
        letter = letters[2];
        return true;
    }
    return false;
}
public:
string longestDiverseString(int a, int b, int c) {
    char c1 = '#', c2 = '#';
    int n = a + b + c;
    string word = "";
    while((int)word.size() < n){
        vector<pair<int, char>> letters = getCharacterFreq(a, b, c);
        pair<int, char> letter;
        cout << "\n";
        if(!getLetter(letters, letter, c1, c2))
            break;
        
        word += letter.second;
        c1 = c2;
        c2 = letter.second;

        if(letter.second == 'a')
            --a;
        else if(letter.second == 'b')
            --b;
        else
            --c;
    }
    return word;
}
};
