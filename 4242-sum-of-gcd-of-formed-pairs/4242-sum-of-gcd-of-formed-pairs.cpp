class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans = 0 ,  n = nums.size() ;
        vector<int>mx(n),pre;
        for(int i = 0 ; i <n ;i ++){
            if(i){
                mx[i] = max(mx[i-1] , nums[i]);
            }
            else{
                mx[i] = nums[i];
            }
        }
        for(int i = 0 ; i <n ;i++){
            long long cur = __gcd(mx[i] , nums[i]);
            pre.push_back(cur);
        }
        sort(pre.begin(),pre.end());
        int l = 0 , r = pre.size()-1;
        while(l<r){
            ans+=__gcd(pre[l],pre[r]);
            l++ , r--;
        }
        return ans ;
    }
};