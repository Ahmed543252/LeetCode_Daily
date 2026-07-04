class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        const int N = 1e5 + 2;
        vector<vector<pair<int, int>>> g(N);
        for (auto it : roads) {
            g[it[0]].push_back({it[1], it[2]});
            g[it[1]].push_back({it[0], it[2]});
        }
        int mn = 2e9;
        vector<int> vis(N, 0);
        auto dfs = [&](auto&& dfs, int u, int par)->void{
            vis[u] = 1;
            for (auto it : g[u]) {
                mn = min(mn, it.second);
                if (it.first == par or vis[it.first])
                    continue;
                dfs(dfs ,it.first,u);
            }
        };
        dfs(dfs,1,-1);
        return mn ;
    }
};