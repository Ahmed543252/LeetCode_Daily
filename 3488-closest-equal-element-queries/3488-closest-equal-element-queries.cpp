class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans, all;
        unordered_map<int, int> mp;
        for (auto it : nums) {
            all.push_back(it);
            mp[it]++;
        }
        for (auto it : nums) {
            all.push_back(it);
        }
        map<int, vector<int>> idx;
        map<int, vector<int>> idx2;
        for (int i = 0; i < all.size(); i++) {
            idx[all[i]].push_back(i);
            if (i < nums.size())
                idx2[nums[i]].push_back(i);
        }
        for (auto it : queries) {
            if (mp[nums[it]] == 1)
                ans.push_back(-1);
            else {
                auto it2 =
                    upper_bound(idx[nums[it]].begin(), idx[nums[it]].end(), it);
                int a = *it2 - it, b = 1e9;
                auto it3 =
                    lower_bound(idx[nums[it]].begin(), idx[nums[it]].end(), it);
                if (it3 != idx[nums[it]].begin()) {
                    --it3;
                    b = abs(*it3 - it);
                } else {
                    if (idx2[nums[it]].size()) {
                        int me = idx2[nums[it]].back();
                        int t = me - it;
                        cout << me << endl;
                        b = abs<int>(nums.size() - t);
                    }
                }
                // cout << a <<" "<<b<<" "<<me <<" "<<it  <<endl;
                int res = min<int>(a, b);
                ans.push_back(res);
            }
        }
        return ans;
    }
};