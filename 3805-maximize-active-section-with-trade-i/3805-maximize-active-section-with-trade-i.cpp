class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> me;
        string t = '1' + s + '1';
        int ans = 0, n = t.size();
        int one = 0;
        for (auto it : s) {
            ans += (it == '1');
            one += (it == '1');
        }
        int cur = 0;
        bool ones = true;
        int i = 0;
        while (i < n) {
            while (i < n and (t[i] - '0') == ones) {
                cur++;
                i++;
            }
            me.push_back(cur);
            cur = 0;
            ones ^= 1;
        }
        if (me.size() <= 3) {
            return ans;
        }
        for (int i = 0; i < me.size(); i += 2) {
            int cur = one;
            if (i == 0) { // ones ..  zeros
                if (i + 1 < me.size()) {
                    cur += me[i + 1];
                }
            } else if (i == me.size() - 1) {
                if (i - 1 >= 0) {
                    cur += me[i - 1];
                }
            } else {
                if (i + 1 < me.size()) {
                    cur += me[i + 1];
                }
                if (i - 1 >= 0) {
                    cur += me[i - 1];
                }
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};