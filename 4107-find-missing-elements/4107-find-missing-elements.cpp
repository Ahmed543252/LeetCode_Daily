class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = 1e9 , mx = -1e9;
        map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
            mn = min(mn ,it);
            mx = max(mx ,it);
        }
        vector<int>ans;
        for(int i =mn ; i<=mx ;i++){
            if(mp[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};