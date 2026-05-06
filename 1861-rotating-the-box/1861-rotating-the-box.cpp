class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> me(m, vector<char>(n));
        for (int i = n - 1, a = 0; i >= 0; i--, a++) {
            for (int j = 0, b = 0; j < m; j++, b++) {
                me[b][a] = boxGrid[i][j];
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (me[i][j] != '#')
                    continue;
                for (int k = i + 1; k < m; ++k) {
                    if (me[k][j] == '.') {
                        me[k - 1][j] = '.';
                        me[k][j] = '#';
                    } else
                        break;
                }
            }
        }
        return me;
    }
};