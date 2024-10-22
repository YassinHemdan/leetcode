class Solution {
public:
int memo[21][21];

bool isValidRegex(int str_idx, int pattern_idx, const string& s,const string& p){
	if(pattern_idx >= (int)p.size())
		return str_idx >= (int)s.size();
	if(memo[str_idx][pattern_idx] != -1)
		return memo[str_idx][pattern_idx];


	bool isMatched = (str_idx < (int)s.size() && (s[str_idx] == p[pattern_idx] || p[pattern_idx] == '.'));

	/*
	 * in the skip part: 1- it does not matter if both chars are equal or not. we try to skip any way
	 * 					 2-  we are handling here if the str reached its end but there are few chars in the
	 * 					 	 pattern we can skip . for example => s: ababz
	 * 					 	 									p: ababzf*.*.*g*
	 * 					 	 in skipping we are only move the pattern index.
	 */
	if(pattern_idx + 1 < (int)p.size() && p[pattern_idx + 1] == '*'){// can we repeat or skip?
		return memo[str_idx][pattern_idx] =
				(isValidRegex(str_idx, pattern_idx + 2, s, p) || // skip
				(isMatched && isValidRegex(str_idx + 1, pattern_idx, s, p))); // repeat
	}

	if(isMatched) // direct comparison. there isn't any * to skip or repeat
		return memo[str_idx][pattern_idx] = isValidRegex(str_idx + 1, pattern_idx + 1, s, p);
    
    return memo[str_idx][pattern_idx] = false;
}
bool isMatch(const string& s,const string& p) {
    memset(memo, -1, sizeof(memo));
    return isValidRegex(0, 0, s, p);
}
};
