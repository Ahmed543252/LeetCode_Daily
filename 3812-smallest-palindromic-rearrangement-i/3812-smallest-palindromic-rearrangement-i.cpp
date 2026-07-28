class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        for(auto it : s)
            mp[it]++;
        string ans ;
        char noos=NULL;
        for(char i = 'a' ;i<='z';i++){
            while(mp[i]>=2){
                ans+=i;
                mp[i]-=2;;
            }
            if(mp[i]>0){
                noos = i;
            }
        }
        string tmp = ans;
        reverse(tmp.begin(),tmp.end());
        if(noos !=NULL)
        ans = ans + noos + tmp;
        else 
        ans = ans + tmp;
        return ans ; 
    }
};