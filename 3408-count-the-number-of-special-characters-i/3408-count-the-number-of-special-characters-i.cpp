class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        for(auto it : word){
            mp[it]++;
        }
        int ans =0 ;
        for(char i ='a',j='A';i<='z'; i++,j++){
            ans+=(mp[i] and mp[j]);
        }
        return ans ;
    }
};