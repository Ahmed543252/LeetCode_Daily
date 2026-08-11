class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int cnt = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                cnt+=nums[i];
            else
                break;
        }
        set<int> st;
        for (auto it : nums)
            st.insert(it);
        while (st.find(cnt) != st.end())
            cnt++;
        return cnt;
    }
};