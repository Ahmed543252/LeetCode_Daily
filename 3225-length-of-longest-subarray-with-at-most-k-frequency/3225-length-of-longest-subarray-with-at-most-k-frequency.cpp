class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0, r = 0, n = nums.size();
        map<int, int> frq;
        while (l < n) {
            while (r < n and frq[nums[r]] + 1 <= k) {
                frq[nums[r]]++;
                r++;
            }
            ans = max(ans, r - l );
            frq[nums[l]]--;
            l++;
        }
        return ans;
    }
};