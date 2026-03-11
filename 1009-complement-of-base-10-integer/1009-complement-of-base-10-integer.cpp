class Solution {
public:
    int msb_pos(int x) { return 31 - __builtin_clz(x); }
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        int ans = 0;
        for (int i = msb_pos(n); i >= 0; i--) {
            if (n & (1 << i))
                continue;
            ans += (1 << i);
        }
        return ans;
    }
};