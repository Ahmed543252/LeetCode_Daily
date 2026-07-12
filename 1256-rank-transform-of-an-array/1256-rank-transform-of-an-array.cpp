class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tmp = arr;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i + 1;
        }
        vector<int> ans;
        for (auto it : tmp)
            ans.push_back(mp[it]);
        return ans;
    }
};