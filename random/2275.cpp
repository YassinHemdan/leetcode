class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(33);
        for(int val : candidates){
            int bit = 0;
            while(val){
                bits[bit++] += (val & 1);
                val = val >> 1;
            }
        }
        return *max_element(bits.begin(), bits.end());
    }
};
