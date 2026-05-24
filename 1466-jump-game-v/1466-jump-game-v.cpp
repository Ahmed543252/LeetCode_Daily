class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        function<int(int)> calc = [&](int idx) -> int {
            int& ret = dp[idx];
            if (~ret)
                return ret;

            ret = 1;
            for (int i = 1; i <= d; i++) {
                if (idx + i >= n || arr[idx + i] >= arr[idx]) {
                    break;
                }
                ret = max(ret, 1 + calc(idx + i));
            }

            for (int i = 1; i <= d; i++) {
                if (idx - i < 0 || arr[idx - i] >= arr[idx]) {
                    break;
                }
                ret = max(ret, 1 + calc(idx - i));
            }

            return ret;
        };

        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, calc(i));
        }

        return ans;
    }
};