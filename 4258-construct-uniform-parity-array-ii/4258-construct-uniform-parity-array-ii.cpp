class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
         int n = nums1.size();
        vector<bool> me(n),tmp;
        sort(nums1.begin(),nums1.end());
        bool a = false, b = false;
        for(auto it : nums1){
            if(it&1){
                a = true;
            }
            else{
                b = true;
            }
        }
        if(!(a and b)){
            return true;
        }
       int mn = 2e9;
       bool f = false , s = false;
       for(int i = 0 ; i <n ; i++){
            if(nums1[i]&1){
                if(mn==2e9 or mn == nums1[i])
                    break;
                else{
                    f = true;
                    break;
                }
                mn = min(mn , nums1[i]);
            }
       }
       mn = 2e9;
       for(int i = 0 ; i <n ; i++){
            if(!(nums1[i]&1)){
                if(mn==2e9 or mn == nums1[i])
                    break;
                else{
                    s = true;
                    break;
                }
            }
            else{
                mn = min(mn , nums1[i]);
            }
       }
       return (s or f);
    }
};