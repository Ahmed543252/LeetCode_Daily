class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector vis(n + 1, vector<int>(m + 1));
        deque<array<int, 3>> dq;
        dq.push_back(array<int, 3>{0, 0, health-grid[0][0]});
        vis[0][0] = 1;
        // R U L D
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {1, 0, -1, 0};
        function<bool(int,int)>ok=[&](int i , int j)->bool{
            if(i<0 or i>=n or j<0 or j>=m or vis[i][j]==1)
            return false;
            return true;
        };
        while (!dq.empty()) {
            auto [a, b, me] = dq.front();
            dq.pop_front();
            if (a == n - 1 and b == m - 1) {
                return (me>0?true:false);
            }
            for (int k = 0; k < 4; k++) {
                int nx =a+dx[k] , ny = b+dy[k];
                if(ok(nx,ny)){
                    vis[nx][ny] = 1;
                    int cur = me - grid[nx][ny];
                    if(grid[nx][ny]==1){
                        dq.push_back(array<int, 3>{nx, ny, cur});
                    }
                    else{
                        dq.push_front(array<int, 3>{nx, ny, cur});
                    }
                }
            }
        }
        return false;
    }
};