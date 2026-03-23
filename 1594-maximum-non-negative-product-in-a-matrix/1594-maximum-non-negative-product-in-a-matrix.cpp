class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<pair<long long,long long>>> dp(n, vector<pair<long long,long long>>(m));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        function<pair<long long,long long>(int, int)> calc = [&](int i, int j) {
            if (i == n - 1 && j == m - 1) {
                return make_pair((long long)grid[i][j], (long long)grid[i][j]);
            }

            if (vis[i][j]) return dp[i][j];
            vis[i][j] = 1;

            long long mx = LLONG_MIN;
            long long mn = LLONG_MAX;

            // down
            if (i + 1 < n) {
                auto [mx2, mn2] = calc(i + 1, j);

                mx = max({mx, mx2 * grid[i][j], mn2 * grid[i][j]});
                mn = min({mn, mx2 * grid[i][j], mn2 * grid[i][j]});
            }

            // right
            if (j + 1 < m) {
                auto [mx2, mn2] = calc(i, j + 1);

                mx = max({mx, mx2 * grid[i][j], mn2 * grid[i][j]});
                mn = min({mn, mx2 * grid[i][j], mn2 * grid[i][j]});
            }

            return dp[i][j] = {mx, mn};
        };

        auto [mx, mn] = calc(0, 0);

        if (mx < 0) return -1;
        return mx % MOD;
    }
};