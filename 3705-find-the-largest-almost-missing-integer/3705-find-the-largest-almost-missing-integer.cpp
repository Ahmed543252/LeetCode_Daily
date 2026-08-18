class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> cur;
        int i = 0, j = k - 1;
        map<int, int> mp;
        for (int k = i; k <= j; k++) {
            cur.push_back(nums[k]);
        }
        map<int, int> me;
        for (auto it : cur) {
            if (me.find(it) == me.end())
                mp[it]++, me[it]++;
        }
        i++, j++;
        for (; j < n; i++, j++) {
            cur.pop_front();
            cur.push_back(nums[j]);
            me.clear();
            for (auto it : cur) {
                if (me.find(it) == me.end())
                    mp[it]++, me[it]++;
            }
        }
        int ans = -1;
        for (auto it : mp) {
            if(it.second == 1)
                ans = max(ans , it.first);
        }
        return ans;
    }
};