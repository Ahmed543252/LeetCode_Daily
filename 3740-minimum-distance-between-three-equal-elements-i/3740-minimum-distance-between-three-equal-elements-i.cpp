class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 1e9;
        for (auto& it : mp) {
            if (it.second.size() < 3)
                continue;
            sort(it.second.begin(), it.second.end());
            for (int j = 2; j < it.second.size(); j++) {
                int cur = abs(it.second[j - 2] - it.second[j - 1]) + abs(it.second[j] - it.second[j - 1]) +
                          abs(it.second[j - 2] - it.second[j]);
                ans = min(ans, cur);
            }
        }
        return (ans==1e9?-1:ans);
    }
};