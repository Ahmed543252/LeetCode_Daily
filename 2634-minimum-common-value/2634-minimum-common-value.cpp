class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> a, b;
        for (auto it : nums1) {
            a[it] = min(1, a[it] + 1);
        }

        for (auto it : nums2) {
            b[it] = min(1, b[it] + 1);
        }
        int ans = INT_MAX;
        for (auto it : nums1) {
            if(a[it] and b[it]){
                ans = min(ans , it);
            }
        }

        for (auto it : nums2) {
            if(a[it] and b[it]){
                ans = min(ans , it);
            }
        }
        return (ans ==INT_MAX ? -1 : ans);
    }
};