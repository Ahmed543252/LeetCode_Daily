class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = -2e9 , n = nums.size(), sum = 0 ;
        vector<int>all;
        for(auto it : nums)
            all.push_back(it),sum+=it;
        int cur =0  ;
        for(int i = 0 ; i <n ; i++){
            cur+=(nums[i]*i);
        }
        ans = max(ans ,cur);
       for(int i = n-1 ; i >=0 ; i--){
        sum-=nums[i];
        cur-=(nums[i]*(n-1));
        cur+=sum;
        sum+=nums[i];
        ans = max(ans ,cur);
       }
        return ans;
    }
};