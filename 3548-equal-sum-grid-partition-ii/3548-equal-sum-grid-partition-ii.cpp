class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total_sum = 0;
                unordered_map<long long, int> min_row, max_row, min_col, max_col;
        vector<long long> row_sum(m, 0), col_sum(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long val = grid[i][j];
                total_sum += val;
                row_sum[i] += val;
                col_sum[j] += val;
                
                if (min_row.find(val) == min_row.end()) min_row[val] = i;
                else min_row[val] = min(min_row[val], i);
                
                if (max_row.find(val) == max_row.end()) max_row[val] = i;
                else max_row[val] = max(max_row[val], i);
                
                if (min_col.find(val) == min_col.end()) min_col[val] = j;
                else min_col[val] = min(min_col[val], j);
                
                if (max_col.find(val) == max_col.end()) max_col[val] = j;
                else max_col[val] = max(max_col[val], j);
            }
        }
                long long s1 = 0;
        for (int r = 0; r < m - 1; r++) {
            s1 += row_sum[r];
            long long s2 = total_sum - s1;
            
            if (s1 == s2) return true;
            
            if (s1 > s2) {
                long long diff = s1 - s2;
                bool is_1d = (r == 0) || (n == 1); 
                if (is_1d) {
                    if (diff == grid[0][0] || diff == grid[r][n - 1]) return true;
                } else {
                    if (min_row.count(diff) && min_row[diff] <= r) return true;
                }
            } else {
                long long diff = s2 - s1;
                bool is_1d = (r == m - 2) || (n == 1); 
                if (is_1d) {
                    if (diff == grid[r + 1][0] || diff == grid[m - 1][n - 1]) return true;
                } else {
                    if (max_row.count(diff) && max_row[diff] >= r + 1) return true;
                }
            }
        }
                s1 = 0;
        for (int c = 0; c < n - 1; c++) {
            s1 += col_sum[c];
            long long s2 = total_sum - s1;
            
            if (s1 == s2) return true;
            
            if (s1 > s2) {
                long long diff = s1 - s2;
                bool is_1d = (c == 0) || (m == 1);
                if (is_1d) {
                    if (diff == grid[0][0] || diff == grid[m - 1][c]) return true;
                } else {
                    if (min_col.count(diff) && min_col[diff] <= c) return true;
                }
            } else {
                long long diff = s2 - s1;
                bool is_1d = (c == n - 2) || (m == 1);
                if (is_1d) {
                    if (diff == grid[0][c + 1] || diff == grid[m - 1][n - 1]) return true;
                } else {
                    if (max_col.count(diff) && max_col[diff] >= c + 1) return true;
                }
            }
        }
        
        return false;
    }
};