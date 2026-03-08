class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        string me = nums[0];
        for (int i = 0; i < me.size(); i++) {
            if (st.count(me) == 0) {
                return me;
            } else {
                me[i] = '1';
                if (st.count(me) == 0) {
                    return me;
                }
                me[i] = '0';
                if (st.count(me) == 0) {
                    return me;
                }
            }
        }
        return me;
    }
};