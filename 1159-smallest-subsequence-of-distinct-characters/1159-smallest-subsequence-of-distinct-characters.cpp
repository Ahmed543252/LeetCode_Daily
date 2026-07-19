class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        map<char, int> last, vis;
        for (int i = 0; i < n; i++) {
            last[s[i]] = i;
        }
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (vis[s[i]]== 0) {
                if (st.empty() or st.top() < s[i])
                    st.push(s[i]), vis[s[i]] = 1;
                else {
                    while (!st.empty() and st.top() > s[i] and
                           last[st.top()] > i) {
                        vis[st.top()] = 0;
                        st.pop();
                    }
                    vis[s[i]] = 1;
                    st.push(s[i]);
                }
            }
        }
        string res;
        while (st.size()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};