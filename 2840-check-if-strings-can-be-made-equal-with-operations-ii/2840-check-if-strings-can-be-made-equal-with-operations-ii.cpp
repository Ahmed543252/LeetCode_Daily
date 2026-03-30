class Solution {
public:
    bool checkStrings(string s1, string s2) {
        map<int, vector<char>> mp, mp2;
        int n = s1.size(), m = s2.size();
        int cur = 0;
        int tmp = 0;
        while (tmp < n) {
            mp[cur].push_back(s1[tmp]);
            tmp += 2;
        }
        cur++;
        tmp = 1;
        while (tmp < n) {
            mp[cur].push_back(s1[tmp]);
            tmp += 2;
        }
        cur = 0;
        tmp = 0;
        while (tmp < m) {
            mp2[cur].push_back(s2[tmp]);
            tmp += 2;
        }
        cur++;
        tmp = 1;
        while (tmp < m) {
            mp2[cur].push_back(s2[tmp]);
            tmp += 2;
        }
        for (auto it : mp) {
            sort(it.second.begin(), it.second.end());
            sort(mp2[it.first].begin(), mp2[it.first].end());
            if (it.second != mp2[it.first])
                return false;
        }
        return true;
    }
};