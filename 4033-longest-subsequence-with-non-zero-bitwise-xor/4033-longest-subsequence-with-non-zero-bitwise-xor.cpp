class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorrr = 0, n = nums.size(),cnt =0 ;
        for (auto it : nums)
            xorrr ^= it,cnt+=(it==0);
            if(cnt == n)
            return 0;
        return (xorrr == 0 ? n - 1 : n);
    }
};