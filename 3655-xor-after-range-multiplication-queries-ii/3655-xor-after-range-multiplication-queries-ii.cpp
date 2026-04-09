class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long binpow(long long base, long long power) {
        long long ret = 1;
        while (power) {
            if (power & 1) ret = (ret * base) % MOD;
            base = (base * base) % MOD;
            power >>= 1;
        }
        return ret;
    }

    long long modInverse(long long a) {
        return binpow(a, MOD - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;

        vector<vector<array<long long, 3>>> cnt(B + 1);

        // process queries
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k > B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                cnt[k].push_back({l, r, v});
            }
        }

        vector<long long> tmp(n, 1);

        for (int i = 1; i <= B; i++) {
            if (cnt[i].empty()) continue;

            fill(tmp.begin(), tmp.end(), 1);

            for (auto &[l, r, v] : cnt[i]) {
                tmp[l] = (tmp[l] * v) % MOD;

                int len = r - l + 1;
                int cur = (len + (i - 1)) / i; // ceil
                int R = l + cur * i;

                if (R < n)
                    tmp[R] = (tmp[R] * modInverse(v)) % MOD;
            }

            for (int j = 0; j < n; j++) {
                if (j - i >= 0)
                    tmp[j] = (tmp[j] * tmp[j - i]) % MOD;
            }

            for (int j = 0; j < n; j++) {
                nums[j] = (1LL * nums[j] * tmp[j]) % MOD;
            }
        }

        int res = 0;
        for (int x : nums) {
            res ^= x;
        }

        return res;
    }
};