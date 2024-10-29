class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        vector<int> freqs;
        for(int& val : arr)
            freq[val]++;
        

        for(auto& p : freq)
            freqs.push_back(p.second);

        sort(freqs.begin(), freqs.end());
        int i=0;
        int n = (int)freqs.size();
        while(i<n && k){
            if(freqs[i] <= k)
                k -= freqs[i], ++i;
            else
                k = 0;
        }
        return n - i;
    }
};
