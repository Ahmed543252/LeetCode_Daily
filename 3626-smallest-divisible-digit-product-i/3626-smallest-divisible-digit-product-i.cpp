class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; i ; i++) {
            int cur = 1, x = i;
            while (x) {
                cur *= x % 10;
                x /= 10;
            }
            if ( cur % t == 0) {
                return i;
            }
        }
        return -1;
    }
};