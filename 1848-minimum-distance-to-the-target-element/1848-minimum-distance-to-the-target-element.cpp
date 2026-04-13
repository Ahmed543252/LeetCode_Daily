class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mn  =  1e9;
        for(int i =0 ; i < nums.size() ; i++){
            if(nums[i] == target){
                mn = min(mn , abs(i-start));
            }
        }
        return mn;
    }
};