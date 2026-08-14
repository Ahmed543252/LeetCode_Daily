class Solution {
public:
    int maximumLengthSubstring(string s) {
       int n = s.size();
       vector pre(n+2,vector<int>(26,0));
       for(int i =0 ; i <n ;i++){
        pre[i][s[i]-'a']++;
       } 
       for(int i =0; i <26 ;i++){
            for(int j = 1; j<n ;j++){
                pre[j][i]+=pre[j-1][i];
            }
       }
       int ans = 0 ;
       for(int i = 0 ; i <n ; i++){
        for(int j = 0; j <n ;j++){
            bool ok = true;
            for(int k = 0;  k< 26 ;k++){
                int val = pre[j][k] - (i-1>=0 ? pre[i-1][k] : 0);
                if(val>2){
                    ok = false;
                    break;
                }
            }
            if(ok)
                ans = max(ans , j-i+1);
        }
       }
       return ans;
    }
};