class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (auto it : patterns) {
            if (word.find(it) != -1)
                ans++;
        }
        return ans;
    }
};