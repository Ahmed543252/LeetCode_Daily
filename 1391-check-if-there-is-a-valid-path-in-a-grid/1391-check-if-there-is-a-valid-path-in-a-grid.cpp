class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        /// 1 R
        //  2 D
        //  3 D and walked from R
        //  4 R and walked from U
        //  5 U and walked from R
        //  6 R and walked from D
        int n = grid.size(), m = grid[0].size();
        vector dis(n + 2, vector<int>(m + 2, 1e9));
        queue<array<int, 3>> q;
        int i = 0, j = 0;
        q.push({i, j, grid[i][j]});
        dis[i][j] = 0;
        auto ok = [&](int i, int j) -> bool {
            if (i < 0 or i >= n or j < 0 or j >= m)
                return false;
            return true;
        };
        vector<vector<vector<int>>> dir = {
            {},
            {{0, -1}, {0, 1}},  // 1
            {{-1, 0}, {1, 0}},  // 2
            {{0, -1}, {1, 0}},  // 3
            {{0, 1}, {1, 0}},   // 4
            {{0, -1}, {-1, 0}}, // 5
            {{0, 1}, {-1, 0}}   // 6
        };
        while (!q.empty()) {
            auto [a, b, me] = q.front();
            q.pop();
            if (a == n - 1 and b == m - 1)
                return true;
            for (auto it : dir[me]) {
                int nx = it[0] + a, ny = b + it[1];
                if (ok(nx, ny) and dis[nx][ny] > dis[a][b] + 1) {
                    for (auto back : dir[grid[nx][ny]]) {
                        if (nx + back[0] == a && ny + back[1] == b) {
                            dis[nx][ny] = dis[a][b]+1;
                            q.push({nx, ny,grid[nx][ny]});
                            break;
                        }
                    }
                }
            }
        }
        return false;
    }
};