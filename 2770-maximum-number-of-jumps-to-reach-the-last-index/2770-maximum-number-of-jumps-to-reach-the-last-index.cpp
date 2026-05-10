class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n =  nums.size();
        vector<vector<int>>has(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n; j++){
                int x = nums[j] - nums[i];
                if(x>= -target and x<=target){
                    has[i].push_back(j);
                }
            }
        }
        vector dp(n+2,-1);
        function<int(int)>calc=[&](int idx)->int{
            if(idx==n-1)
                return 0;
            if(has[idx].size()==0)
                return -1e9;
            int &ret = dp[idx];
            if(~ret)
                return ret;
            ret = -1e9;
            for(auto it : has[idx]){
                ret= max(ret , 1+ calc(it));
            }
            return ret;
        };
        int ans = calc(0);
        return ans <=0 ?-1 : ans;
    }
};