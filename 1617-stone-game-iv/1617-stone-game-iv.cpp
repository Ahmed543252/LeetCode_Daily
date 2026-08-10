class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int>dp(n+2,-1);
       auto calc=[&](auto &&calc, int me)->int{
            if(me==0){
                return false;
            }
            int &ret = dp[me];
            if(~ret)
            return ret;
            ret = 0;
            for(int i =1 ; i*i<=me;i++){
                if(calc(calc,me - i*i)==false){
                    ret = 1;
                }
            }
            return ret;
       };
       bool ans = calc(calc,n);
       return ans;
    }
};