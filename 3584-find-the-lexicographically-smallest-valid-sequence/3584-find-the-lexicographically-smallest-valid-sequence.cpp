class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int> ans;
        int n = word1.size(), m = word2.size();
        vector<int> lst(m, -1);
        int i = n - 1;
        for (int j = m - 1; j >= 0; j--) {
            while (i >= 0 and word1[i] != word2[j]) {
                i--;
            }
            if (i >= 0)
                lst[j] = i, --i;
        }
        i = 0;
        bool ok = true;
        for (int j = 0; j < m; j++) {
            while (i < n) {
                if (i < n and word1[i] == word2[j]) {
                    ans.push_back(i);
                    i++;
                    break;
                }
                if (ok and ((j + 1 == m) or (lst[j + 1] > i))) {
                    ok = false;
                    ans.push_back(i);
                    i++;
                    break;
                }
                i++;
            }
        }
        vector<int>tmp;
        return (ans.size() != m ? tmp : ans);
    }
};