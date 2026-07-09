class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<vector<int>> adj(n + 2);
        for (int i = 1; i < n; i++) {
            int a = nums[i - 1], b = nums[i];
            if (abs(a - b) <= maxDiff) {
                adj[i - 1].push_back(i);
                adj[i].push_back(i - 1);
            }
        }
        int cur = 0;
        vector<int> id(n + 2), vis(n + 2, 0);
        auto dfs = [&](auto&& dfs, int node) -> void {
            vis[node] = 1;
            id[node] = cur;
            for (auto it : adj[node]) {
                if (!vis[it])
                    dfs(dfs, it);
            }
        };
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(dfs, i);
                cur++;
            }
        }
        vector<bool> ans;
        for (auto it : queries) {
            int u = it[0], v = it[1];
            if (id[u] == id[v])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};