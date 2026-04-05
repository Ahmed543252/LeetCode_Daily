class Solution {
public:
    bool judgeCircle(string moves) {
        int a , b;
        a = b = 0 ;
        for(auto it : moves){
            a+=(it=='U');
            a-=(it=='D');
            b+=(it=='R');
            b-=(it=='L');
        } 
        return (a==0 & b==0);
    }
};