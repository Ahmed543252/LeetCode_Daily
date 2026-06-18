class Solution {
public:
    double angleClock(int hour, int minutes) {
        double effect = 0.5 * (double)minutes;
        double hours = (hour %12)*30 + effect;
        double minute = 6.0 * minutes;
        double momkn = abs(hours-minute);
        double ans = min(momkn , 360.0 - momkn);
        return ans; 
    }  
};