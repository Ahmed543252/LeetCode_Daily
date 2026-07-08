class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> cnt(n + 1, 0), pow(n + 1, 1), pre(n + 1, 0),
            pre_val(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] != '0') {
                int me = (s[i - 1] - '0');
                pre_val[i] = (pre_val[i - 1] * 10 + me) % MOD;
                pre[i] = pre[i - 1] + me;
                cnt[i] = cnt[i - 1] + 1;

            } else {
                pre_val[i] = pre_val[i - 1];
                pre[i] = pre[i - 1];
                cnt[i] = cnt[i - 1];
            }
            pow[i] = (pow[i - 1] * 10) % MOD;
        }
        vector<int> ans;
        for (auto it : queries) {
            int l = it[0], r = it[1], len = (cnt[r + 1] - cnt[l]);
            if (len == 0) {
                ans.push_back(0);
                continue;
            }
            long long sum = (pre[r + 1] - pre[l]) % MOD;
           long long val = (pre_val[r + 1] - (pre_val[l] * pow[len]) % MOD) % MOD;
            if (val < 0) {
                val += MOD;
            }
            long long res = (sum * val) % MOD;
            ans.push_back((int)res);
        }
        return ans;
    }
};