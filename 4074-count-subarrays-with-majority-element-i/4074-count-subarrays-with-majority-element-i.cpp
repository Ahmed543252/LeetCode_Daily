class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>pre(n);
        pre[0] = (nums[0] == target);
        for(int i=  1 ; i <n ; i++){
            pre[i] = pre[i-1]+(nums[i] == target);
        }
        int ans =0 ;
        for(int i = 0 ;i  <n ;i++){
            for(int j = i;j<n;j++){
                int cnt = pre[j] -(i-1>=0?pre[i-1]:0);
                int len = (j-i+1)/2;
                ans+=(cnt>len);
            }
        }
        return ans;
    }
};