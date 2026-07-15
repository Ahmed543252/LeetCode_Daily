class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        double me = (double)n/2;
        int e = me * (2*2+(n-1)*2);
        int o = me * (2+(n-1)*2);
        // cout <<e <<" "<<o<<endl;
        return __gcd(o,e);
    }
};