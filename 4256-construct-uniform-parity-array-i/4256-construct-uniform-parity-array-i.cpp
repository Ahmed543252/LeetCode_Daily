class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<bool> me(n),tmp;
        for (int i = 0; i < n; i++) {
            if (nums1[i] & 1) {
                me[i] = 1;
            }
        }
        tmp = me;
        // try to make all of them evens
        for (int i = 0; i < n; i++) {
            if (me[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        int val = nums1[j] - nums1[i];
                        if (val % 2 == 0)
                            me[i] = 0;
                    }
                }
            }
        }
        int sum = 0;
        for (auto it : me)
            sum += it;
        if (sum == 0)
            return true;
        me = tmp;
        // tru odds
        for (int i = 0; i < n; i++) {
            if (me[i] == 0) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        int val = nums1[j] - nums1[i];
                        if (val % 2 != 0)
                            me[i] = 1;
                    }
                }
            }
        }
         sum = 0;
        for (auto it : me)
            sum += it;
        if (sum == n)
            return true;
        return false;
    }
};