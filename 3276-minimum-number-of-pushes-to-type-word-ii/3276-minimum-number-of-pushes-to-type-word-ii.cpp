class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0,cnt = 0,idx =1;
        int cur = word.size();
        vector<pair<int, int>> frq(26, {0, 0});
        for (auto it : word) {
            frq[it - 'a'].first++;
            frq[it - 'a'].second = (it - 'a');
        }
        sort(frq.rbegin(), frq.rend());
        for(int i = 0 ; i < 26 ;i++){
            ans += frq[i].first*(i/8 + 1);
        }
        return ans;
    }
};