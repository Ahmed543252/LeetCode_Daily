class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans= 0;
        map<int,vector<int>>mp , pre;
        for(auto it : reservedSeats){
            mp[it[0]].push_back(it[1]);
        }
        for(auto it : mp){
            pre[it.first].assign(11,0);
            for(auto itt : it.second){
                pre[it.first][itt]++;
            }
        }
        for(auto &it : pre){
            int sz = it.second.size();
            for(int i =1 ; i<sz ;i++){
                it.second[i] +=it.second[i-1];
            }
            // cout <<endl;
        }
        ans += max<int>(0 , (n - mp.size())*2);
        for(auto &[_,vec] : pre){
            int a =vec[5]-vec[1];
            int b =vec[7] - vec[3];
            int c =vec[9] - vec[5];
            if(a==0 and c==0)
                ans+=2;
            else if(a==0 or b==0 or c==0)
                ans++;
        }
        return ans;
    }
};