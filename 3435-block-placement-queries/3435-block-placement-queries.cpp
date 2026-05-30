class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) : n(n) {
        tree.assign(4 * n, 0);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val; 
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int start, int end, int l, int r) {
        if (l > end || r < start) return 0;
        if (l <= start && end <= r) return tree[node];
        
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool>ans;
        set<int>obs;
        int mx = 0 ;
        obs.insert(0);
        for(auto &it : queries){
            if(it[0]==1){
                obs.insert(it[1]);
            }
            mx = max(mx, it[1]);
        }
        SegmentTree seg(mx+2); // any point at seg has a abs diff between it and prv
        int prv = 0 ;
        for(auto it = next(obs.begin());it!=obs.end();it++){ 
            int val = *it ;
            seg.update(val,val - prv);
            prv = val;
        }
        for(int i = queries.size()-1; i>=0 ;i--){
            auto it = queries[i];
            if(it[0]==1){
                // remove this obstacle 
                auto me = obs.lower_bound(it[1]);
                auto prv = prev(me);
                auto nxt = next(me);
                if(nxt!=obs.end()){
                    seg.update(*nxt,*nxt-*prv);
                }
                seg.update(it[1],0);
                obs.erase(it[1]);
            }
            else{
                // push ans
                auto me = obs.lower_bound(it[1]);
                auto prv = *prev(me);
                if(seg.query(0,it[1])>=it[2] or (it[1]- prv >=it[2])){
                    ans.push_back(true);
                }
                else{
                    ans.push_back(false);
                }
            }
        } 
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};