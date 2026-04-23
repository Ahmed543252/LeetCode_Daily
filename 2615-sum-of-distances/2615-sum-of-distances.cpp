class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<long long ,vector<long long >>idx;
        int  n = nums.size();
        vector<long long >ans(n);
        for(int i =0 ; i < n ; i++){
            idx[nums[i]].push_back(i);
        }
        for(auto it : idx){
            // do prefix on this arr
            vector<long long >me;
            long long  cur = 0 ;
            for(auto itt : it.second){
                cur += itt;
                me.push_back(cur);
            }
            if(it.second.size()>1){
                for(int i =0 ; i < me.size() ; i++){
                    // cur ans is sum of all elements prv me and sum of all after me - (me * x) ---> x is a number of elements next me 
                    if(i>0)
                        ans[it.second[i]] = ((i) * it.second[i]) - me[i-1],cout <<ans[it.second[i]]<<" ";
                    if(i<me.size()){
                        long long sz = me.size()-1 - i;
                        long long  plus = (me[me.size()-1] - me[i]) - ( it.second[i] * sz) ;
                        ans[it.second[i]] +=plus;
                        // cout <<sz <<" "<< plus <<" "<<(me[me.size()-1] - me[i])<<" "<<nums[it.second[i]]<<endl;
                    }
                }
            }
        }
        return ans;
    }
};