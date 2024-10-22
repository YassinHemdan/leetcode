class Solution {
private:
    int getGPD(int n){
        vector<int> divisors;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (n / i == i)
                    divisors.push_back(i);
                else{
                    divisors.push_back(i);
                    divisors.push_back(n / i);
                }
            }
        }
        sort(divisors.rbegin(), divisors.rend());
        return divisors[1];
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        int count = 0;
        for(int i = n - 2 ; i > -1 ; --i){
            while(nums[i] > nums[i + 1]){
                int gpd = getGPD(nums[i]);
                if(gpd == 1)
                    return -1; // a prime number
                ++count;
                nums[i] /= gpd;
            }
        }
        return count;
    }
};
