class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0 ;
        for(int i = num1 ; i <=num2; i++){
            string me = to_string(i);
            for(int j =1 ; j < me.size()-1;j++){
                if(me[j]>me[j-1] and me[j]>me[j+1]){
                    ans++;
                }
                if(me[j]<me[j-1] and me[j]<me[j+1]){
                    ans++;
                }
            }
        }
        return ans ;
    }
};