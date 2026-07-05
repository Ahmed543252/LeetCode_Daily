class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].size();
        vector dp(n + 2, vector<pair<int, int>>(m + 2, {-1, -1}));
        const int MOD = 1e9 + 7 ;
        auto ok = [&](int i, int j) -> bool {
            if (i < 0 or i >= n or j < 0 or j >= m or board[i][j]=='X')
                return false;
            return true;
        };
        auto calc = [&](auto&& calc, int i, int j) -> pair<int, int> {
            if(i==0 and j==0){
                return {0,1};
            }
            pair<int,int> &ret = dp[i][j];
            if(ret.first!=-1){
                return ret;
            }
            ret = {-2e9,0};
            if(ok(i-1,j)){
                // up
                int val =(board[i][j]=='S'?0:board[i][j]-'0');
                auto me = calc(calc,i-1,j);
                if(me.first+val > ret.first){
                    ret.first = me.first+val;
                    ret.second = me.second;
                }
                else if(me.first+val == ret.first){
                    ret.second =(ret.second + me.second )%MOD ;
                }
            }
            if(ok(i,j-1)){
                // L
                int val =(board[i][j]=='S'?0:board[i][j]-'0');
                auto me = calc(calc,i,j-1);
                 if(me.first+val > ret.first){
                    ret.first = me.first+val;
                    ret.second = me.second;
                }
                else if(me.first+val == ret.first){
                    ret.second =(ret.second + me.second )%MOD ;
                }
            }
             if(ok(i-1,j-1)){
                // L
                int val =(board[i][j]=='S'?0:board[i][j]-'0');
                auto me =  calc(calc,i-1,j-1);
                 if(me.first+val > ret.first){
                    ret.first = me.first+val;
                    ret.second = me.second;
                }
                else if(me.first+val == ret.first){
                    ret.second =(ret.second + me.second )%MOD ;
                }
            }
            return ret;
        };
        auto ans = calc(calc,n-1,m-1);
        vector<int>res(2);
        res[0] = ans.first , res[1] = ans.second;
        if(res[0]<0){
            return {0,0};
        }
        return res;
    }
};