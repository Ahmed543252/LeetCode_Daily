class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0 , n = nums1.size() , m = nums2.size();
        for(int i = 0 ; i < n ; i++){
            int l = i , r = m-1 ,cur = -1;
            while(l<=r){
                int mid = l + (r -l)/2;
                auto can=[&](int  mid)->bool{
                    return nums2[mid]>=nums1[i];
                };
                if(can(mid)){
                    cur = mid;
                    l = mid +1 ;
                }
                else{
                    r = mid - 1;
                }
            }
            int dis = (cur!= -1 ? cur - i : 0);
            ans = max(ans,dis );
        }
        return ans ;
    }
};