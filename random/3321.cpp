class Solution {
private:
    set<pair<int, int>> selected;
    set<pair<int, int>> waiting;
    unordered_map<int, int> mp;
    long long sum;

    void add(const pair<int, int>& candidate, int x){
        selected.insert(candidate);
        sum += 1LL * candidate.first * candidate.second;

        if((int)selected.size() > x){
            pair<int, int> cand = *selected.begin();
            waiting.insert(cand);

            sum -= 1LL * cand.first * cand.second;
            selected.erase(cand);
            
        }
    }
    void remove(const pair<int, int>& candidate){
        if(waiting.find(candidate) != waiting.end())
            waiting.erase(candidate);
        
        if(selected.find(candidate) != selected.end()){
            sum -= 1LL * candidate.first * candidate.second;
            selected.erase(candidate);

            if(!waiting.empty()){
                pair<int, int> cand = *waiting.rbegin();
                waiting.erase(cand);
                
                selected.insert(cand);
                sum += 1LL * cand.first * cand.second;
            }
        }
    }
public:
    Solution(){
        selected.clear();
        waiting.clear();
        mp.clear();
        sum = 0;
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int ansIdx = 0;
        vector<long long> ans(n - k + 1);
        for(int i=0 ; i<n ; ++i){
            pair<int, int> cand = {mp[nums[i]], nums[i]};
            if(mp[nums[i]] > 0) // its frequency increased, remove the old one
                remove(cand);
            
            // add the new one
            mp[nums[i]]++;
            cand.first++;
            add(cand, x);

            if(i >= k){ // a candidate skill will is changed. Remove the old one, add the new one
                int idx = i - k;
                pair<int, int> changedCandidate = {mp[nums[idx]], nums[idx]};
                remove(changedCandidate);

                mp[nums[idx]]--;
                changedCandidate.first--;
                if(changedCandidate.first > 0)
                    add(changedCandidate, x);
            }
            if(i >= k - 1)
                ans[ansIdx++] = sum;
        }
        return ans;
    }
};
