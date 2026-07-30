class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        set<int> st;
        for (auto it : word)
            st.insert(it);
        int cur = st.size();
        int idx = 1;
        while (cur >= 8) {
            ans += idx * 8;
            cur -= 8;
            idx++;
        }
        ans += idx * cur;
        return ans;
    }
};