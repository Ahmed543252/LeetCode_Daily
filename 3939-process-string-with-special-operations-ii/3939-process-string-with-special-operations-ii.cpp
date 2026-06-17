class Solution {
public:
    char processStr(string s, long long k) {
         int n = s.length();
        vector<long long> L(n, 0);
        for (int i = 0; i < n; i++) {
            long long prev = (i == 0) ? 0 : L[i - 1];

            if (s[i] >= 'a' && s[i] <= 'z') {
                L[i] = prev + 1;
            } else if (s[i] == '*') {
                L[i] = max(0LL, prev - 1);
            } else if (s[i] == '#') {
                L[i] = prev * 2;
            } else if (s[i] == '%') {
                L[i] = prev;
            }
        }

        if (k >= L[n - 1]) {
            return '.';
        }
        long long idx = k;
        for (int i = n - 1; i >= 0; i--) {
            long long prev = (i == 0) ? 0 : L[i - 1];
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (idx == prev) {
                    return s[i];
                }
            } else if (s[i] == '*') {
                continue;
            } else if (s[i] == '#') {
                if (idx >= prev) {
                    idx -= prev;
                }
            } else if (s[i] == '%') {
                idx = prev - 1 - idx;
            }
        }

        return '.';
    }
};