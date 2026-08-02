class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector dp(n+2,vector<int>(n+2,-1));
        function<int(int ,int )>calc=[&](int i , int j)->int{
            if(i==j)
                return piles[i];
            int &ret = dp[i][j];
            if(~ret)
            return ret;
            int l = piles[i] - calc(i+1,j);
            int r = piles[j]-calc(i,j-1);
            return ret = max(l,r);
        };     
        return calc(0,piles.size()-1)>=0;
    }
};