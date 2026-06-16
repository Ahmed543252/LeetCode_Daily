class Solution {
public:
    string processStr(string s) {
        string ans;
        for (auto it : s) {
            if (islower(it)) {
                ans += it;
            } else {
                if (it == '#') {
                    ans+=ans;
                } else if (it == '*') {
                    if (ans.size())
                        ans.pop_back();
                } else {
                    if (ans.size())
                        reverse(ans.begin(), ans.end());
                }
            }
        }
        return ans;
    }
};