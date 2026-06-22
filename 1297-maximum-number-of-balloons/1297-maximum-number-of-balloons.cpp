class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s = "balloon";
        vector<int> frq(30, 0);
        int ans = 1e9;
        for (auto it : text)
            frq[it - 'a']++;
        for (auto it : s) {
            if (it == 'l' or it == 'o') {
                ans = min(ans, frq[it - 'a']/2);
            } else
                ans = min(ans, frq[it - 'a']);
        }
        return (ans == 1e9 ? 0 : ans);
    }
};