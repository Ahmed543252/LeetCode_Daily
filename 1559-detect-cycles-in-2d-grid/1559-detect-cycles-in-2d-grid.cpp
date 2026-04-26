class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        function<bool(int,int,int,int)> dfs = [&](int i, int j, int pi, int pj) {
            vis[i][j] = 1;

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;

                if (grid[x][y] != grid[i][j])
                    continue;

                if (x == pi && y == pj)
                    continue;

                if (vis[x][y])
                    return true;

                if (dfs(x, y, i, j))
                    return true;
            }

            return false;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1))
                        return true;
                }
            }
        }

        return false;
    }
};