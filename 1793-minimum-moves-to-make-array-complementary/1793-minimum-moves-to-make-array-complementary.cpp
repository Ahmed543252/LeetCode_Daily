class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>diff(2*limit+100);
        for(int i = 0 ; i <n /2 ;i++){
            int a = nums[i] , b = nums[n-i-1];
            int sum = a+b ;
            int l = min(a,b)+1 , r = max(a,b)+limit;
            // if i replace two numberes
            diff[2]+=2;
            // replace one element 
            diff[l]-=1;
            diff[r+1]+=1;
            // if sum is equal to x
            diff[sum]-=1;
            diff[sum+1]+=1;
        }
        int ans = 2e9,cur_sum=0;
        for(int i = 2 ; i <=2*limit;i++ ){
            cur_sum+=diff[i];
            ans =min(ans ,cur_sum);
        }
        return ans ;
    }
};