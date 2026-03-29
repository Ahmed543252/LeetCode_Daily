class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        map<int, vector<char>> mp, mp2;
        int n = s1.size(), m = s2.size();
        int cur = 0;
        for (int i = 0; i * 2 < n; i++) {
            int tmp = i;
            while (tmp < n) {
                mp[cur].push_back(s1[tmp]);
                tmp += 2;
            }
            cur++;
        }
        cur = 0;
        for (int i = 0; i * 2 < m; i++) {
            int tmp = i;
            while (tmp < n) {
                mp2[cur].push_back(s2[tmp]);
                tmp += 2;
            }
            cur++;
        }
        for (auto it : mp) {
            sort(it.second.begin(), it.second.end());
            sort(mp2[it.first].begin(), mp2[it.first].end());
            for(auto i : it.second)
            cout <<i<<" ";
            cout <<endl;
            for(auto i : mp2[it.first])
            cout <<i<<" ";
            cout <<endl;
            if (it.second != mp2[it.first])
                return false;
        }
        return true;
    }
};