class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> all;
        function<void(int, char, string)> calc = [&](int idx, char lst,
                                                     string me) {
            if (idx == n) {
                all.push_back(me);
                return;
            }
            if (lst == 'a') {
                calc(idx + 1, 'b', me + 'b');
                calc(idx + 1, 'c', me + 'c');
            } else if (lst == 'b') {
                calc(idx + 1, 'a', me + 'a');
                calc(idx + 1, 'c', me + 'c');

            } else if (lst == 'c') {
                calc(idx + 1, 'b', me + 'b');
                calc(idx + 1, 'a', me + 'a');
            } else {
                calc(idx + 1, 'b', me + 'b');
                calc(idx + 1, 'a', me + 'a');
                calc(idx + 1, 'c', me + 'c');
            }
        };
        calc(0, 'd', "");
        sort(all.begin(), all.end());
        k--;
        if (k >= all.size())
            return "";
        return all[k];
    }
};