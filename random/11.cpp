class Solution {
public:
    int maxArea(const vector<int>& height) { // o(n) time
        int r = 0;
        int l = (int)height.size() - 1;
        int mx = 0;

        while(r < l){
            int length = l - r;
            mx = max(mx, length * min(height[r], height[l]));
            if(height[r] <= height[l])
                ++r;
            else
                --l;
        }
        return mx;
    }
};
