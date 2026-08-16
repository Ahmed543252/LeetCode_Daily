class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        map<int, int> frq;
        for (auto it : stones)
            frq[it % 3]++;
        bool ok = false;
        if (frq[0] % 2 == 0) {
          return (frq[1]>=1 and frq[2]>=1);
        } else {
           int val = abs(frq[1] - frq[2]);
           return val > 2;
        }
        return ok;
    }
};