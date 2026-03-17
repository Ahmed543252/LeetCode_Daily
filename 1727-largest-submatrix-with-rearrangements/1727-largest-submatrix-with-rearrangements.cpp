class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int> hi(m);
        for (int i = 0; i < n; i++) {
            // loop at each col
            for (int j = 0; j < m; j++) {
                if (matrix[i][j])
                    hi[j]++;
                else
                    hi[j] = 0;
            }
            vector<int> cur = hi;
            sort(cur.rbegin(), cur.rend());
            for (int i = 0; i < cur.size(); i++) {
                ans = max(ans, cur[i] * (i + 1));
            }
        }

        return ans;
    }
};