class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int N = 1e5 + 10;
        vector<int> frq(N, 0);
        for (auto it : costs) {
            frq[it]++;
        }
        int ans = 0;
        for (int i = 1; i < N; i++) {
            int x = frq[i];
            if (x == 0)
                continue;
            int cur = coins / i;
            cur = min(cur, x);
            if (cur == 0)
                break;
            ans += cur;
            coins -= cur * i;
        }
        return ans;
    }
};