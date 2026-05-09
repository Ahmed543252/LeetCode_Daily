class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        // vector to each layer
        vector vis(n + 2, vector<bool>(m + 2, false));
        vector ans(n , vector<int>(m ));
        int i = 0, j = 0;
        while (i < n and j < m and vis[i][j] == false) {
            int top = i;
            int left = j;
            int bottom = n - i - 1;
            int right = m - j - 1;
            int a = top;
            int b = left;
            vector<int> cur;
            while (b <= right && !vis[a][b]) {
                cur.push_back(grid[a][b]);
                vis[a][b] = true;
                b++;
            }
            b--;
            a++;
            while (a <= bottom && !vis[a][b]) {
                cur.push_back(grid[a][b]);
                vis[a][b] = true;
                a++;
            }
            a--;
            b--;
            while (b >= left && !vis[a][b]) {
                cur.push_back(grid[a][b]);
                vis[a][b] = true;
                b--;
            }
            b++;
            a--;
            while (a >= top + 1 && !vis[a][b]) {
                cur.push_back(grid[a][b]);
                vis[a][b] = true;
                a--;
            }


            int shift = k %cur.size() ;
            vector<int> nw;
            for (int me = shift; me < cur.size(); me++)
                nw.push_back(cur[me]);
            for (int me = 0; me < shift; me++)
                nw.push_back(cur[me]);


            int idx = 0;
            while (b <= right ) {
               
                ans[a][b] = nw[idx];
                idx++;
                b++;
            }
            b--;
            a++;
            while (a <= bottom) {
               ans[a][b] = nw[idx];
                idx++;
                a++;
            }
            a--;
            b--;
            while (b >= left ) {
                ans[a][b] = nw[idx];
                idx++;
                b--;
            }
            b++;
            a--;
            while (a >= top + 1 ) {
                ans[a][b] = nw[idx];
                idx++;
                a--;
            }
            i++;
            j++;
        }
        return ans;
    }
};