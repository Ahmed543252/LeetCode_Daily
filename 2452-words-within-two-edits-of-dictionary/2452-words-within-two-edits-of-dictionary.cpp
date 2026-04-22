class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        for(int i = 0 ; i < queries.size();i++){
            for(int  k = 0 ; k < dictionary.size();k++){
                string a= queries[i], b=dictionary[k];
                int cnt = 0 ;
                for (int j = 0; j < a.size(); j++) {
                    cnt += (a[j] != b[j]);
                    if (cnt > 2)
                        break;
                }
                if (cnt <= 2) {
                    ans.push_back(a);
                    break;
                }
            }
        }
        return ans;
    }
};