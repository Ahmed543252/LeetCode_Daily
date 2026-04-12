class Solution {
public:
    int minimumDistance(string word) {
        char cur = 'A';
        vector<pair<int, int>> pos(30);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                int me = cur - 'A';
                pos[me] = {i, j};
                cur++;
            }
        }
        int n = word.size();
        vector dp(
            n + 1,
            vector(6, vector(7, vector(6, vector(7, vector<int>(3, -1))))));
        function<int(int, int, int, int, int, int)> calc =
            [&](int idx, int i1, int j1, int i2, int j2, int momkn) -> int {
            if (idx == n)
                return 0;
            int& ret = dp[idx][i1][j1][i2][j2][momkn];
            if (~ret)
                return ret;
            ret = 1e9;
            if (momkn == 0) {
                int me = word[idx] - 'A';
                auto& [a, b] = pos[me];
                int cost = abs(i1 - a) + abs(j1 - b);
                ret = min(ret, calc(idx + 1, i1, j1, a, b, 1));
                ret = min(ret, cost + calc(idx + 1, a, b, i2, j2, 0));
            } else {
                int me = word[idx] - 'A';
                auto& [a, b] = pos[me];
                int cost1 = abs(i1 - a) + abs(j1 - b);
                int cost2 = abs(i2 - a) + abs(j2 - b);
                ret = min(ret, cost1 + calc(idx + 1, a, b, i2, j2, 1));
                ret = min(ret, cost2 + calc(idx + 1, i1, j1, a, b, 1));
            }
            return ret;
        };
        auto [a, b] = pos[word[0]-'A'];
        int ans = calc(1, a, b, 0, 0, 0);
        return ans;
    }
};