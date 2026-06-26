#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
#include <ext/pb_ds/assoc_container.hpp>
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans = 0;
        int n = nums.size();
        vector<long long> pre(n, 0) ;
        pre[0] = (target == nums[0]);
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (nums[i] == target);
        }
        ordered_set<long long> st;
        st.insert(1);
        for (int i = 0; i < n; i++) {
            long long cur = 2 * pre[i] - i ;

            ans += st.order_of_key(cur );

            st.insert(cur);
        }
        return ans;
    }
};