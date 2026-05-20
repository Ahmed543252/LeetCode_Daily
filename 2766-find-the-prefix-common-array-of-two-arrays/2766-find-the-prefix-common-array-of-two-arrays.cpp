class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        int n = A.size();
        unordered_set<int>cur;
        unordered_map<int,int>a,b;
        for(int i = 0 ;i < n ; i++){
            a[A[i]]++;
            b[B[i]]++;
            if(b[A[i]])
                cur.insert(A[i]);
            if(a[B[i]])
                cur.insert(B[i]);
            ans.push_back(cur.size());
        }
        return ans ;
    }
};