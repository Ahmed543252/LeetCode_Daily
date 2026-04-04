class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        vector<vector<char>>me;
        int n = encodedText.size() ;
        if(n==0)
            return "";
        int col = n/rows;
        // cout <<col<<endl;
            vector<char>cur;
        for(int i =0 ; i < n ;i++){
            cur.push_back(encodedText[i]);
            if(cur.size()==col){
                me.push_back(cur);
                cur.clear();
            }
        }
        string res;
        int i = 0 ,j = 0 ;
         n = me.size();
        int m = me[0].size();
        while(j<m){
            int cur_i = i , cur_j = j;
            while(cur_i<n && cur_j<m){
                res+=me[cur_i][cur_j];
                cur_i++;
                cur_j++;
            }
            j++;
        }
        while(res.back()==' ')
            res.pop_back();
        return res;
    }
};