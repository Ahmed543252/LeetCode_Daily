class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int a , b , c;
        a = b = c = 0 ;
        for(auto it : moves){
            a+=(it=='L');
            b+=(it=='R');
            c+=(it=='_');
        }
        int ans =max(a,b) - min(a,b) + c;
        return ans ;
    }
};