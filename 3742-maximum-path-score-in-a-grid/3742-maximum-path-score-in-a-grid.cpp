class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        const int NEG = -1e9;

        vector dp(n, vector(m, vector<int>(k + 1, NEG)));
        for (int rem = 0; rem <= k; rem++) {
            dp[n - 1][m - 1][rem] =
                (rem >= min(1, grid[n - 1][m - 1])) ? grid[n - 1][m - 1] : NEG;
        }
        auto ok = [&](int i, int j) -> bool {
            if (i < 0 or i >= n or j < 0 or j >= m)
                return false;
            return true;
        };
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int rem = 0; rem <= k; rem++) {

                    if (i == n - 1 && j == m - 1)
                        continue;

                    int cost = min(1, grid[i][j]);

                    if (ok(i + 1, j) && rem - cost >= 0) {
                        dp[i][j][rem] =
                            max(dp[i][j][rem],
                                grid[i][j] + dp[i + 1][j][rem - cost]);
                    }

                    if (ok(i, j + 1) && rem - cost >= 0) {
                        dp[i][j][rem] =
                            max(dp[i][j][rem],
                                grid[i][j] + dp[i][j + 1][rem - cost]);
                    }
                }
            }
        }
        int ans = dp[0][0][k];
        return (ans < 0 ? -1 : ans);
    }
};