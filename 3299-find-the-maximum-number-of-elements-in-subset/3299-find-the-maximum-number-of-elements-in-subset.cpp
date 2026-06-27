class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 1;
        map<long long ,int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        if(mp[1]%2==0){
            ans = max(ans , mp[1]-1);
        }
        else{
            ans = max(ans ,mp[1]);
        }
        for(auto &[x,frq]:mp){
            if(x==1)
            continue;
            long long  cur = 0 , me  =x;
            while(mp.find(me)!=mp.end() and mp[me]>=2){
                cur+=2;
                me = me*me;
            }
            if(mp.find(me)!=mp.end())
                cur++;
            else
                cur-=1;
            ans = max<long long>(ans , cur);
        }
        return ans ;
    }
};