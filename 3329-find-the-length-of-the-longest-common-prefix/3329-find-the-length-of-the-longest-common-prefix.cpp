class Solution {
public:
    struct Trie {
        struct Node {
            Node* nxt[10];
            int cnt_pref;
            Node() {
                memset(nxt, 0, sizeof(nxt));
                cnt_pref = 0;
            }
        };

    public:
        Node* root = new Node();
        void insert(string& s) {
            Node* cur = root;
            for (auto it : s) {
                int idx = it - '0';
                if (cur->nxt[idx] == NULL) {
                    cur->nxt[idx] = new Node();
                }
                cur = cur->nxt[idx];
                cur->cnt_pref++;
            }
        }
        int calc(string& s) {
            Node* cur = root;
            int ret = 0;
            for (int i = 0; i < s.size(); i++) {
                int idx = s[i] - '0';
                if (cur->nxt[idx] == NULL) {
                    return ret;
                }
                cur = cur->nxt[idx];
                ret = max(i + 1, ret);
            }
            return ret;
        }
    };
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie T;
        for(auto it : arr1){
            string me = to_string(it);
            T.insert(me);
        }
        int ans = 0 ;
        for(auto it : arr2){
            string me = to_string(it);
            int cur = T.calc(me);
            ans = max(ans, cur);
        }
        return ans ;
    }
};