class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> a, tmp = nums;
        sort(tmp.begin(), tmp.end());
        for (auto it : tmp)
            a.push_back(it);
        for (auto it : tmp)
            a.push_back(it);
        int n = nums.size();
        for (int i = 0; i + n - 1 < a.size(); i++) {
            bool ok = true;
            for (int j = i, k = 0; k < n; k++,j++) {
                if (nums[k] != a[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                return true;
        }
        return false;
    }
};