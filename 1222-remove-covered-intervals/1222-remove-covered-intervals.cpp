class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<vector<int>, int> mp;
        for (int i = 0; i < n; i++) {
            if(mp.find(intervals[i])==mp.end())
            mp[intervals[i]]= i;
        }
        vector<int> vis(n);
        auto ok = [&](vector<int>& a, vector<int>& b) -> bool {
            int x = a[0], y = a[1];
            int l = b[0], m = b[1];
            if (x <= l and m <= y)
                return 1;
            // if (l <= x and y <= m)
            //     return 1;
            return 0;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[mp[intervals[j]]] or i==j)
                    continue;
                if (ok(intervals[i], intervals[j]))
                    vis[mp[intervals[j]]] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[mp[intervals[i]]] == 0)
                ans++;
        }
        return ans;
    }
};