class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int>dis(n,1e9);
        unordered_map<int,vector<int>>mp;
        for(int i = 0 ; i<n ; i ++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        dis[0]=0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(top == n-1){
                return dis[top];
            }
            if(top-1>=0 and dis[top-1] > dis[top]+1){
                q.push(top-1);
                dis[top-1] =dis[top]+1;
            }
            if(top+1<n and dis[top+1] > dis[top]+1){
                q.push(top+1);
                dis[top+1] =dis[top]+1;
            }
            for(auto it : mp[arr[top]]){
                if(dis[it] >dis[top]+1){
                    q.push(it);
                    dis[it] = dis[top]+1;
                }
            }
            mp[arr[top]].clear();
        }
        return -1;
    }
};