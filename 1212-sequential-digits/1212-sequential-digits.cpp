class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> me;
        queue<int> q;
        map<int, int> vis;
        for (int i = 1; i <= 8; i++) {
            me.push_back(i);
            q.push(i);
            vis[i] = 1;
        }
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            int x = f % 10;
            if (f < 1e9 and x != 9) {
                f = (f * 10) + (x + 1);
                q.push(f);
                me.push_back(f);
            }
        }
        sort(me.begin(), me.end());
        me.erase(unique(me.begin(), me.end()), me.end());
        auto l = lower_bound(me.begin(), me.end(), low) - me.begin();
        auto r = upper_bound(me.begin(), me.end(), high) - me.begin();
        vector<int> ans;
        for (int i = l; i < r; i++) {
            ans.push_back(me[i]);
        }
        return ans;
    }
};