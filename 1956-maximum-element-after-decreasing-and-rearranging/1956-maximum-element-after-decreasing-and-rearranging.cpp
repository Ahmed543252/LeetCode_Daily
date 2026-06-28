class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans = 1, n = arr.size();
        sort(arr.begin(), arr.end());
        if (arr[0] != 1)
            arr[0] = 1;
        for (int i = 1; i < n; i++) {
            int cur = abs(arr[i] - arr[i - 1]);
            if (cur > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};