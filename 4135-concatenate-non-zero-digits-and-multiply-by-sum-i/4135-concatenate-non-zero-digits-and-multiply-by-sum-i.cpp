class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string s;
        while (n) {
            int cur = n % 10;
            if (cur != 0) {
                s += (cur + '0');
                sum += cur;
            }
            n /= 10;
        }
        reverse(s.begin(), s.end());
        long long ans = 0;
        if (s.size()) {
            int x = stoll(s);
            ans = x * sum;
        }
        return ans;
    }
};