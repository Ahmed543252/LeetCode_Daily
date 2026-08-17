class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<long long >pre(n+1);
        for(int i =0  ;i < n; i++){
            if(i){
                pre[i] = pre[i-1]+stoneValue[i];
            }
            else{
                pre[i] = stoneValue[i];
            }
        }
        vector dp(n + 1, vector<long long>(n + 1, -1));
        auto calc = [&](auto&& calc, int l, int r) -> long long {
            if (l >= r)
                return 0;
            long long& ret = dp[l][r];
            if (~ret)
                return ret;
            ret = 0;
            for(int i = l; i<r;i++){
                long long a = pre[i] - (l-1>=0?pre[l-1]:0);
                long long b = pre[r] - pre[i];
                if(a>b){
                    ret = max(ret ,b + calc(calc,i+1,r));
                }  
                else if(a==b){
                    ret = max(ret ,b + calc(calc,i+1,r));
                    ret = max(ret ,a + calc(calc,l,i));
                }
                else{
                    ret = max(ret ,a + calc(calc,l,i));
                }
            }
            return ret;
        };
        long long ans  = calc(calc,0,n-1);
        return (int)ans;
    }
};