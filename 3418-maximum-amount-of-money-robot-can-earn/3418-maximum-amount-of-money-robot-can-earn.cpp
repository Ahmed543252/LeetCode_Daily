class Solution {
public:
    int dp[501][501][3];
    vector<vector<int>> coins1;
    int n, m;
    bool ok(int i, int j) { 
        return i >= 0 && i < n && j >= 0 && j < m; 
    }
    int calc(int i, int j, int k) {
        if (i == n - 1 && j == m - 1) {
            if (coins1[i][j] >= 0) {
                return coins1[i][j];
            } else {
                if (k < 2) return 0;
                else return coins1[i][j];
            }
        }

        int &ret = dp[i][j][k];
        if (ret != -1000000000)  
            return ret;

        ret = -1000000000;

        if (ok(i + 1, j)) {
            if (coins1[i][j] >= 0) {
                ret = max(ret, coins1[i][j] + calc(i + 1, j, k));
            } else {
                if (k < 2) {
                    ret = max(ret, calc(i + 1, j, k + 1));
                    ret = max(ret, coins1[i][j] + calc(i + 1, j, k));
                } else {
                    ret = max(ret, coins1[i][j] + calc(i + 1, j, k));
                }
            }
        }

        if (ok(i, j + 1)) {
            if (coins1[i][j] >= 0) {
                ret = max(ret, coins1[i][j] + calc(i, j + 1, k));
            } else {
                if (k < 2) {
                    ret = max(ret, calc(i, j + 1, k + 1));
                    ret = max(ret, coins1[i][j] + calc(i, j + 1, k));
                } else {
                    ret = max(ret, coins1[i][j] + calc(i, j + 1, k));
                }
            }
        }

        return ret;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();
        coins1 = coins;

        for (int i = 0; i < 501; i++)
            for (int j = 0; j < 501; j++)
                for (int k = 0; k < 3; k++)
                    dp[i][j][k] = -1000000000;

        return calc(0, 0, 0);
    }
};