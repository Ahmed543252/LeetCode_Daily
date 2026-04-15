class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = 1e9;
        int n = words.size();
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == target) {
                ans = min(ans, abs(i - startIndex));
                ans = min(ans, startIndex + (n - i));
                ans = min(ans, i + (n - startIndex));
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};