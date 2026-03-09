class Solution {
public:
    const int N = 202, MOD = 1e9 + 7;
    int limitt;
    int dp[202][202][2];
    int calc(int ones, int zeros, bool lst) {
        if (!ones && !zeros)
            return 1;
        int& ret = dp[ones][zeros][lst];
        if (~ret)
            return ret;
        ret = 0;
        if (lst) { // lst == 0 ?
            for (int i = 1; i <= min(limitt, ones); i++) {
                ret = (ret + calc(ones - i, zeros, false));
                if (ret >= MOD)
                    ret -= MOD;
            }
        } else {
            for (int i = 1; i <= min(limitt, zeros); i++) {
                ret = (ret + calc(ones, zeros - i, true));
                if (ret >= MOD)
                    ret -= MOD;
            }
        }
        return ret;
    };
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        limitt = limit;
         int ans = (calc( one, zero, 0) + calc( one, zero, 1));
        if (ans >= MOD)
            ans -= MOD;
        return ans;
    }
};