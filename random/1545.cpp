class Solution {
public:
// S1 = "0"
// S2 = S1 + 1 + REV(INV(S1))
// So our kth bit will be in the left part or right part or in the middle
// three possible ways to know the value of our bit
// if k == mid -> return 1;
// if k < mid -> return the value from our prev string with the same index
// if k > mid -> return the (inverted value) from our prev stirng with k = length - k + 1
char findKthBit(int n, int k) {
    if(n == 1)
        return '0';

    int length = (1 << n) - 1;
    int mid = length / 2  + 1;

    if(k == mid)
        return '1';
    
    if(k < mid)
        return findKthBit(n - 1, k);
    
    return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
}
};
