class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        int gc = 0, sum = 0;
        vector<int>me;
        int rem = grid[0][0] % x;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
                if(rem != (grid[i][j]%x))
                    return -1;
                me.push_back(grid[i][j]);
            }
        }
        sort(me.begin(),me.end());
        int cur_sum = 0 ;
        int ans = 1e9;
        for(int i = 0 ; i <me.size() ; i++){
            // all elments is equal to me[i]??
            // all el before me is equal to me target = ((i-1)*me[i] - cur_sum)/x
            // all el after me is equal to target = (sum-(cur_sum+me[i])) - (me.size()-(i+1))
            int a = (i*me[i] - cur_sum);
            int cur =a /x;
            cur+=((sum-(cur_sum+me[i]))- ((me.size()-(i+1))*me[i]))/x;
            ans = min(ans , cur);
            cur_sum+=me[i];
        }
        return ans;
    }
};