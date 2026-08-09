class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> pre = piles;
        for (int i = 1; i < n; i++) {
            pre[i] += pre[i - 1];
        }
        vector dp(n + 2, vector<int>(100, -1e9));
        function<int(int, int)> calc = [&](int idx, int lst) -> int {
            if (idx >= n)
                return 0;
            int& ret = dp[idx][lst];
            if (ret != -1e9)
                return ret;
            ret = -1e9;
            for (int can = 1; can <= 2*lst; can++) {
                if (idx + can <= n) {
                    int gain =
                        pre[idx + can - 1] - (idx - 1 >= 0 ? pre[idx - 1] : 0);
                    int nw = max(lst,can);
                    ret = max(ret, gain - calc(idx + can,nw));
                } else {
                    break;
                }
            }
            return ret;
        };
        int ans = calc(0, 1);
        int res  = (pre[n-1]+ans)/2; 
        return res;
    }
};