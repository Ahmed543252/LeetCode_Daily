class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n  = nums.size();
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(n==3){
            return 4;
        }
        bitset<32>me(n);
        int ans = 0 ;
        for(int i = 31 ; i>=0 ;i--){
            if(me[i]==1){
                ans = (1ll<<i)*2;
                return ans ;
            }
        }
        return ans;
    }
};