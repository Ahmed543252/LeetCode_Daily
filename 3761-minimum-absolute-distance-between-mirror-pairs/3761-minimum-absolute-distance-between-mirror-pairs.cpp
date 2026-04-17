class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<long long , int > mp;
        int ans = 1e9 , n = nums.size();
        auto calc=[&](int n)->long long {
            string s ;
            s = to_string(n);
            while(s.size() && s.back() == '0')
                s.pop_back();
            reverse(s.begin(),s.end());
            long long  res = stoll(s);
            return res;
        };
        for(int i = 0 ; i < n; i++){
            if(mp.find(nums[i])!=mp.end()){
                ans = min(ans , abs(i - mp[nums[i]]));
            }
            mp[calc(nums[i])] = i ;
        }
        return (ans == 1e9 ? -1 : ans);
    }
};