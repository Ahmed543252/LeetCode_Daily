class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        map<long long ,long long >mp;
        for (auto it : asteroids) {
            mp[it]++;
        }
        long long  cur = mass;
        while (mp.size()) {
            auto it = mp.upper_bound(cur);
            if (it == mp.begin())
                return false;
            auto it2 = prev(it);
            // cout << it2->first << endl;
            cur+=(it2->first);
            mp[it2->first]--;
            if(mp[it2->first]==0){
                mp.erase(it2);
            }
        }
        return true;
    }
};