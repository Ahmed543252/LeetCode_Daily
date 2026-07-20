class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        ans = grid;
        while(k>0){
            for(int i = m-1 ; i > 0 ;i--){
                for(int j = 0 ; j <n ;j++){
                    swap(ans[j][i] , ans[j][i-1]);
                }
            }
            for(int i = n-1 ; i>0 ;i--){
                swap(ans[i][0],ans[i-1][0]);
            }
            k--;
        }
        return ans ;
    }
};