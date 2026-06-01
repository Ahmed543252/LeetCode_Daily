class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum = 0 ;
        deque<int>dq;
        for(auto it : cost)
            dq.push_back(it);
        sort(dq.begin(),dq.end());
        while(dq.size()>=3){
            sum+=dq.back();
            dq.pop_back();
            sum+=dq.back();
            dq.pop_back();
            dq.pop_back();
        }
        while(dq.size()){
            sum+=dq.back();
            dq.pop_back();
        }
        return sum ;
    }
};