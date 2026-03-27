class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i & 1) {
                    int x = mat[i][j], want = mat[i][((j - k ) % m+m)%m];
                    if (x != want)
                        return false;
                } else {
                    int x = mat[i][j], want = mat[i][(j + k) % m];
                    if (x != want)
                        return false;
                }
            }
        }
        return true;
    }
};