class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = 2e9;
        for(auto it : nums){
            int cur = it,sum = 0 ;
            while(cur){
                sum+=cur%10;
                cur/=10;
            }
            mn = min(mn , sum);
        }
        return mn;
    }
};