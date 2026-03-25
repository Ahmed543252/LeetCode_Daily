class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0 ;
        int n = grid.size() , m = grid[0].size();
        for(int i = 0 ; i <n ;i++){
            for(int j =0 ; j < m ; j++){
                sum+=grid[i][j];
            }
        }
        long long cur = 0 ;
        for(int i = 0 ; i <n ;i++){
            for(int j =0 ; j < m ; j++){
                cur+=grid[i][j];
            }
            if(cur == (sum-cur)){
                return true;
            }
        }
        cur = 0 ;
        for(int i = 0 ; i <m ;i++){
            for(int j =0 ; j < n ; j++){
                cur+=grid[j][i];
            }
            if(cur == (sum-cur)){
                return true;
            }
        }
        return false;
    }
};