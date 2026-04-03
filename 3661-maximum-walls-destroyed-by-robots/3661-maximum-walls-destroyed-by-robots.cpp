class Solution {
public:
    int n;
    vector<pair<int,int>> v;
    vector<int> walls;
    vector<vector<int>> dp;

    int sum(int l, int r){
        auto left = lower_bound(walls.begin(), walls.end(), l);
        auto right = upper_bound(walls.begin(), walls.end(), r);
        return right - left;
    }

    int calc(int idx, int lst){
        if(idx == n) return 0;

        int &ret = dp[idx][lst];
        if(ret != -1) return ret;

        ret = 0;

        // skip
        ret = max(ret, calc(idx+1, lst));

        int pos = v[idx].first;
        int dis = v[idx].second;

        int L = (idx ? max(pos - dis, v[idx-1].first + 1) : pos - dis);
        int R = (idx < n-1 ? min(pos + dis, v[idx+1].first - 1) : pos + dis);

        // left
        int lcount;
        if(lst){
            lcount = sum(max(pos - dis, v[idx-1].first + v[idx-1].second + 1), pos);
        } else {
            lcount = sum(L, pos);
        }

        // right
        int rcount = sum(pos, R);

        ret = max(ret, lcount + calc(idx+1, 0));
        ret = max(ret, rcount + calc(idx+1, 1));

        return ret;
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& w) {
        n = robots.size();
        walls = w;

        v.clear();
        for(int i = 0; i < n; i++){
            v.push_back({robots[i], distance[i]});
        }

        sort(v.begin(), v.end());
        sort(walls.begin(), walls.end());

        dp.assign(n, vector<int>(2, -1));

        return calc(0, 0);
    }
};