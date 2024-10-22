auto init = []() {cin.tie(0); ios::sync_with_stdio(0); return 1;}();
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int rightMax = arr[n - 1];
        arr[n - 1] = -1;
        for(int i = n - 2 ; i>-1 ; --i){
            int temp = arr[i];
            arr[i] = rightMax;
            rightMax = max(rightMax, temp);
        }
        return arr;
    }
};
