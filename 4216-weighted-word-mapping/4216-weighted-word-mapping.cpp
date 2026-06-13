class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans ;
        for(auto it : words){
            int cur =0 ;
            for(auto itt : it){
                cur+=(weights[itt-'a']);
            }
            cur%=26;
            cur = 26 - cur;
            ans+=char(cur+'a'-1);
        
        }
        return ans ;
    }
};