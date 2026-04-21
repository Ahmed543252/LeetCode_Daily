class Solution {
public:
    class DSU {
    public:
        vector<int> par, sz;

        DSU(int n) {
            par.resize(n);
            sz.resize(n, 1);
            iota(par.begin(), par.end(), 0);
        }

        int findPar(int u) {
            return par[u] == u ? u : par[u] = findPar(par[u]);
        }

        void join(int u, int v) {
            u = findPar(u);
            v = findPar(v);
            if (u == v)
                return;
            if (sz[u] > sz[v])
                swap(u, v);
            par[u] = v;
            sz[v] += sz[u];
        }
    };
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);
        for (auto it : allowedSwaps) {
            dsu.join(it[0], it[1]);
        }
        map<int, multiset<int>> mp;
        for (int i = 0; i < n; i++) {
            int p = dsu.findPar(i);
            mp[p].insert(source[i]);
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int p = dsu.findPar(i);

            auto it = mp[p].find(target[i]);

            if (it != mp[p].end()) {
                mp[p].erase(it);
            } else {
                ans++;
            }
        }
        return ans ;
    }
};