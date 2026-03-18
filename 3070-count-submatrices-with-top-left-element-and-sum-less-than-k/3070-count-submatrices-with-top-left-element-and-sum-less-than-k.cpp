class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        vector pre(n, vector<int>(m));
        function<bool(int, int)> ok = [&](int i, int j) -> bool {
            if (i < 0 or i >= n or j < 0 or j >= m)
                return false;
            return true;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i][j] = grid[i][j];
                if (ok(i - 1, j))
                    pre[i][j] += pre[i - 1][j];
                if (ok(i, j - 1))
                    pre[i][j] += pre[i][j - 1];
                if (ok(i - 1, j - 1))
                    pre[i][j] -= pre[i - 1][j - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(pre[i][j]<=k)
                    ans++;
            }
        }
        return ans ;
    }
};