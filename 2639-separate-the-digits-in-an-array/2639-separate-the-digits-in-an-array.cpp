class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto it : nums){
            string cur = to_string(it);
            for(auto itt : cur){
                ans.push_back(itt-'0');
            }
        }
        return ans ;
    }
};