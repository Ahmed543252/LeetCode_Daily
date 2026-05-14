class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> me;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            me.push_back(i);
        }
        me.push_back(n-1);
        if (nums == me)
            return true;
        return false;
    }
};