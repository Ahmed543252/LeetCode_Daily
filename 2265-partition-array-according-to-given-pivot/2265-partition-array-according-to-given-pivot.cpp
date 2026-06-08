class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a, b, c;
        for (auto it : nums) {
            if (it == pivot) {
                b.push_back(it);
            } else if (it < pivot) {
                a.push_back(it);
            } else {
                c.push_back(it);
            }
        }
        vector<int> ans;
        for (auto it : a)
            ans.push_back(it);

        for (auto it : b)
            ans.push_back(it);

        for (auto it : c)
            ans.push_back(it);
        return ans;
    }
};