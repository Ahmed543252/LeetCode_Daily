class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector ans(n, vector<int>(m));
        const int MOD = 12345;
        vector<int> me;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                me.push_back(grid[i][j]);
            }
        }
        int sz = me.size();
        vector<int> pre(sz), suff(sz);
        pre[0] = me[0];
        suff[sz - 1] = me[sz - 1];
        for (int i = 1, j = sz - 2; i < sz; i++, j--) {
            pre[i] = ((pre[i - 1]%MOD) * (me[i]%MOD)) % MOD;
            suff[j] = ((suff[j + 1]%MOD) * (me[j]%MOD)) % MOD;
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a = 1, b = 1;
                if (cur - 1 >= 0) {
                    a = pre[cur - 1];
                }
                if (cur + 1 < sz) {
                    b = suff[cur + 1];
                }
                ans[i][j] = ((a%MOD) * (b%MOD)) % MOD;
                cur++;
            }
        }
        return ans;
    }
};