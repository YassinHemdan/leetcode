class Solution {
private:
    int sumSquares(int n){
        int num = 0;
        while(n){
            int d = n % 10;
            num += d * d;
            n /= 10;
        }
        return num;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = sumSquares(slow);
            fast = sumSquares(sumSquares(fast));
        }while(slow != fast);

        return slow == 1;
    }
};
