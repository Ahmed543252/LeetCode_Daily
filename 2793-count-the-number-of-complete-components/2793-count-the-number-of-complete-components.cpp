class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n);
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> in(n), out(n), all;
        function<void(int)> dfs = [&](int node) {
            vis[node] = 1;
            all.push_back(node);
            for (auto it : adj[node]) {
                out[node]++;
                if (!vis[it]) {
                    dfs(it);
                }
            }
        };
        int ans = 0, a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                all.clear();
                dfs(i);
                bool ok = true;
                for(auto it : all){
                    ok &=(out[it]==all.size()-1);
                }
                ans+=ok;
            }
        }
        return ans;
    }
};