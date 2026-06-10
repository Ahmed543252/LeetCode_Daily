class Solution {
public:
    vector<vector<int>> max_table, min_table;
    int LOG;

    void buildSparseTable(vector<int>& nums) {
        int n = nums.size();
        LOG = __lg(n) + 1;

        max_table.assign(LOG, vector<int>(n));
        min_table.assign(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            max_table[0][i] = nums[i];
            min_table[0][i] = nums[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                int half = 1 << (j - 1);
                max_table[j][i] =
                    max(max_table[j - 1][i], max_table[j - 1][i + half]);
                min_table[j][i] =
                    min(min_table[j - 1][i], min_table[j - 1][i + half]);
            }
        }
    }

    int query(int l, int r) {
        int j = __lg(r - l + 1);
        int hi = max(max_table[j][l], max_table[j][r - (1 << j) + 1]);
        int lo = min(min_table[j][l], min_table[j][r - (1 << j) + 1]);
        return hi - lo;
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        buildSparseTable(nums);
        int n = nums.size();
        priority_queue<array<int, 3>> pq;
        pq.push(array<int, 3>{query(0, n - 1), 0, n - 1});
        set<pair<int, int>> vis;
        vis.insert({0, n - 1});
        long long  ans = 0;
        while (k--) {
            auto [val, ll, rr] = pq.top();
            ans += val;
            pq.pop();
            auto try_it = [&](int l, int r) {
                if (l >= 0 and l < n and r >= 0 and r < n and
                    vis.find({l, r}) == vis.end() and l <= r ) {
                    pq.push(array<int, 3>{query(l, r), l, r});
                    vis.insert({l, r});
                }
            };
            // l    r
            try_it(ll-1,rr);
            try_it(ll+1,rr);
            try_it(ll,rr+1);
            try_it(ll,rr-1);
        }
        return ans; 
    }
};