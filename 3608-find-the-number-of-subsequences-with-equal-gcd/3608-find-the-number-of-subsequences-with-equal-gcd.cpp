class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector dp(n + 2, vector(202, vector<int>(202, -1)));
        const int MOD = 1e9 + 7;
        auto calc = [&](auto&& calc, int idx, int a, int b) -> int {
            if (idx == n) {
                return (((a > 0 or b > 0) and a == b) ? 1 : 0);
            }
            int& ret = dp[idx][a][b];
            if (~ret)
                return ret;
            ret = 0;
            ret = (ret + calc(calc,idx+1,a,b))%MOD;
            ret = (ret + calc(calc,idx+1,__gcd(a,nums[idx]),b))%MOD;
            ret = (ret + calc(calc,idx+1,a,__gcd(b,nums[idx])))%MOD;
            return ret;
        };
        int ans = calc(calc,0,0,0);
        return ans;
    }
};