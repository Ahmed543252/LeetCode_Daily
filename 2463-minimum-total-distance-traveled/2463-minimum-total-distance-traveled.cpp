class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size() , m = factory.size();
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector dp(n+2 , vector<long long >(m+2,-1));
        function<long long(int , int )>calc=[&](int i , int j)->long long{
            if(i==n)
                return 0;
            if(j==m)
                return 1e15;
            long long &ret = dp[i][j];
            if(~ret)
                return ret;
            ret = 1e15;
            ret = min(ret , calc(i,j+1));
            long long cost = 0;
            long long pos = (long long )factory[j][0];
            long long  lim = (long long )factory[j][1];
            for(int k = 0 ; k <lim && k+i<n ;k++){
                 cost += abs(robot[i+k] - pos);
                ret= min(ret ,cost + calc(i+k+1,j+1));
            }
            return ret;
        };
        return calc(0,0);
    }
};