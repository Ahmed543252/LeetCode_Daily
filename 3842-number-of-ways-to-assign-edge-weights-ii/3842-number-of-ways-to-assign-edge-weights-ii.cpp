class Solution {
public:
    long long fastPower(long long a, long long b, long long m) {
        if (b < 0)
            return 0;
        long long result = 1;
        a = a % m;
        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b = b / 2;
        }

        return result;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<int> adj[n + 2];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans;
        const int LG = 30;
        vector<int> tin(n + 2), tout(n + 2), depth(n + 2);
        vector up(LG, vector<int>(n + 2));
        int timer = 0;
        function<void(int, int)> dfs = [&](int node, int parent) {
            tin[node] = ++timer;
            up[0][node] = parent;
            for (auto it : adj[node]) {
                if (it == parent)
                    continue;
                depth[it] = depth[node] + 1;
                dfs(it, node);
            }
            tout[node] = ++timer;
        };
        auto is_ansector = [&](int u, int v) {
            return tin[u] <= tin[v] && tout[u] >= tout[v];
        };
        auto LCA_U_V = [&](int u, int v) {
            if (is_ansector(u, v))
                return u;
            if (is_ansector(v, u))
                return v;
            for (int pw = LG - 1; pw >= 0; --pw) {
                if (is_ansector(up[pw][u], v))
                    continue;
                u = up[pw][u];
            }
            return up[0][u];
        };

        dfs(1, 1);
        for (int pw = 1; pw < LG; pw++) {
            for (int node = 1; node <= n; node++) {
                up[pw][node] = up[pw - 1][up[pw - 1][node]];
            }
        }
        const int MOD = 1e9 + 7;
        for (auto it : queries) {
            int u = it[0], v = it[1];
            int dis = depth[u] + depth[v] - 2 * depth[LCA_U_V(u, v)];
            int res = fastPower(2, dis - 1, MOD);
            ans.push_back(res);
        }
        return ans;
    }
};