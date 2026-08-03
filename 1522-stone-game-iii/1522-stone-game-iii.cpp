class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector dp(n + 2, vector<int>(3, -1e9));
        auto calc = [&](auto &&calc,int idx, int turn) -> int {
            if (idx >= n)
                return 0;
            int& ret = dp[idx][turn];
            if (ret!=-1e9)
                return ret;
            ret = -1e9;
            int ch1 = stoneValue[idx];
            int ch2 = stoneValue[idx];
            int ch3 = stoneValue[idx];
            if (idx + 1 < n) {
                ch2 += stoneValue[idx + 1];
                ch3 += stoneValue[idx + 1];
                if (idx + 2 < n)
                    ch3 += stoneValue[idx + 2];
            }
            if (turn) {
                ret = max(ret, ch1 - calc(calc,idx + 1, 0));
                ret = max(ret, ch2 - calc(calc,idx + 2, 0));
                ret = max(ret, ch3 - calc(calc,idx + 3, 0));
            } else {
                ret = max(ret, ch1 - calc(calc,idx + 1, 1));
                ret = max(ret, ch2 - calc(calc,idx + 2, 1));
                ret = max(ret, ch3 - calc(calc,idx + 3, 1));
            }
            return ret;
        };
        int ans = calc(calc,0, 1);
        // cout <<ans<<endl;
        if (ans == 0)
            return "Tie";
        if (ans > 0)
            return "Alice";
        return "Bob";
    }
};