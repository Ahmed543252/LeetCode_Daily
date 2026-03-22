class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size(),m= mat[0].size();
        vector one(n,vector<int>(m));
        vector two(n,vector<int>(m));
        vector three(n,vector<int>(m));
        for(int i = 0,a=0 ; i <n ; i++,a++){
            for(int j = 0,b = n-1 ; j < m ; j++,b--){
                one[i][j] = mat[b][a];
            }
        }
        for(int i = 0,a=n-1 ; i <n ; i++,a--){
            for(int j = 0,b = n-1 ; j < m ; j++,b--){
                two[i][j] = mat[a][b];
            }
        }
        for(int i = 0,a=n-1 ; i <n ; i++,a--){
            for(int j = 0,b = 0 ; j < m ; j++,b++){
                three[i][j] = mat[b][a];
            }
        }
        if(mat == target or one == target or two == target or three == target)
        return 1;
        return 0;
    }
};