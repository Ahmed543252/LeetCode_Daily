class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>q;
        vector<int>dis(n+2,false);
        q.push(start);
        dis[start]=0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(arr[top]==0)
                return true;
            if(top + arr[top] < n and dis[top + arr[top]]==0){
                q.push(top + arr[top]);
                dis[top + arr[top]] = dis[top]+1;
            }
             if(top - arr[top] >=0 and dis[top - arr[top]]==0){
                q.push(top - arr[top]);
                dis[top - arr[top]] = dis[top]+1;
            }
        }
        return false;
    }
};