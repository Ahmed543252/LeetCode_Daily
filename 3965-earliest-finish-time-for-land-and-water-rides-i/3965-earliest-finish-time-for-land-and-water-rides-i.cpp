class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(),m = waterStartTime.size();
       int ans = 2e9;
        for(int i = 0 ; i < n ;i ++){
            for(int j = 0 ; j < m ; j++){
                int a = landStartTime[i] + landDuration[i];
                if(waterStartTime[j]<=a){
                    a+=waterDuration[j];
                }
                else{
                    a+=abs(waterStartTime[j]-a)+waterDuration[j];
                }
                int b = waterStartTime[j]+waterDuration[j];
                if(landStartTime[i]<=b){
                    b+=landDuration[i];
                }
                else{
                    b+=abs(b-landStartTime[i])+landDuration[i];
                }
                ans = min({ans , a , b});
            }
        }
        return ans ;
    }
};