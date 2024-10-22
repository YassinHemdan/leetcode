class Solution {
private:
    void digitPositionFreq(int num, vector<vector<int>>& position){
        int idx = 0;
        while(num){
            int digit = num % 10;
            num /= 10;
            position[idx][digit]++;
            ++idx;
        }
    }
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> position(9, vector<int>(10));
        long long n = nums.size();
        for(int& val : nums) 
            digitPositionFreq(val, position);
        
        long long sum = 0;
        for(int p=0 ; p<9 ; ++p){
            if((int)position[p].size() <= 1)
                continue;
            
            long long accumulate = 0;
            for(int d=0 ; d<9 ; ++d){
                if(position[p][d] == 0)
                    continue;
                long long freq = position[p][d];
                sum += freq * (n - freq);
                sum -= freq * accumulate;

                accumulate += freq;
            }
        }
        return sum;
    }
};
