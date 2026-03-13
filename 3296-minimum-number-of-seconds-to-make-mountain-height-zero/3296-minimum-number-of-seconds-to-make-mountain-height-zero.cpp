class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        auto can=[&](long long  mid)->bool{
            long long res = 0 ;
            for(auto it : workerTimes){
            long long a = 1 , b= 1, c =(mid/it)*2;
                res+=(sqrtl(1+4*c)-1)/2;
                if(res>=mountainHeight)
                    return true;
            }
            return false;
        };
       long long  l =1  , r =  1e18 , ans = -1;
       while(l<=r){
            long long mid = l+(r-l)/2;
            if(can(mid)){
                ans = mid;
                r = mid -1;
            }
            else{
                l = mid + 1;
            }
       }
       return ans ;
    }
};