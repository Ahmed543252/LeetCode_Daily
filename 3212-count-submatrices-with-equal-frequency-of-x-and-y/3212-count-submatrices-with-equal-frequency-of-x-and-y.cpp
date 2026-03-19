class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        vector pre(n, vector<int>(m));
        vector pre1(n, vector<int>(m));
        function<bool(int, int)> ok = [&](int i, int j) -> bool {
            if (i < 0 or i >= n or j < 0 or j >= m)
                return false;
            return true;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X')
                    pre[i][j] = 1, pre1[i][j] = 1;
                else if (grid[i][j] == 'Y')
                    pre[i][j] = -1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ok(i - 1, j))
                    pre[i][j] += pre[i - 1][j], pre1[i][j] += pre1[i - 1][j];
                if (ok(i, j - 1))
                    pre[i][j] += pre[i][j - 1], pre1[i][j] += pre1[i][j - 1];
                if (ok(i - 1, j - 1))
                    pre[i][j] -= pre[i - 1][j - 1],
                        pre1[i][j] -= pre1[i - 1][j - 1];

                if (pre[i][j] == 0 && pre1[i][j])
                    ans++;
            }
            cout << endl;
        }
        return ans;
    }
};