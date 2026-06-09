class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long  mx = 0 , mn = 2e9;
        for(auto it : nums){
            mn = min<long long>(mn , it);
            mx= max<long long>(mx,it);
        }
        long long ans = (mx - mn)*k;
        return ans ;
    }
};