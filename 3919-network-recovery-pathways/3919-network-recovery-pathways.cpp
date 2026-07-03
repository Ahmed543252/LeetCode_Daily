class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<pair<int,int>> g[n+2];
        for(auto it : edges){
            g[it[0]].push_back({it[1],it[2]});
        }
        auto can=[&](int mid)->bool{
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
            vector<long long>dis(n+2,1e18);
            pq.push({0,0});
            dis[0] = 0;
            while(!pq.empty()){
                auto [cost , node] = pq.top();
                pq.pop();
                if(cost > dis[node])
                 continue;
                 for(auto it : g[node]){
                    long long nw_dis = it.second + dis[node];
                    if(it.second>=mid and nw_dis<dis[it.first] and online[it.first]){
                        dis[it.first] = nw_dis;
                        pq.push({nw_dis,it.first});
                    }
                 }
            }
            return (dis[n-1]<=k);
        };
        int l = 0 , r = 2e9 , ans =-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(can(mid)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};