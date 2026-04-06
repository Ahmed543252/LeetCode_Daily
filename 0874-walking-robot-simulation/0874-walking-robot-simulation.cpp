class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int cur_state =0  ; /// up
        map<pair<int,int>,int>frq;
        for(auto it : obstacles){
            frq[{it[0],it[1]}]++;
        }
        int ans = 0;
        int x = 0 , y =0 ;
        for(auto it : commands){
            if(it == -1){
                cur_state=(cur_state+1)%4; 
            }
            else if(it == -2){
                cur_state=(cur_state-1 +4)%4;
            }
            else{
                if(cur_state==0){
                    // up 
                    bool ok = false;
                    for(int i = 1 ;i<=it;i++){
                        if(frq[{x,y+i}]){
                            y+=i-1;
                            ok = true;
                            break;
                        }
                    }
                    if(ok == false){
                        y+=it;
                    }
                }
                else if(cur_state==1){
                    // right
                     bool ok = false;
                    for(int i = 1 ;i<=it;i++){
                        if(frq[{i+x,y}]){
                            x+=i-1;
                            ok = true;
                            break;
                        }
                    }
                    if(ok == false){
                        x+=it;
                    }
                }
                else if(cur_state==2){
                    // down
                     bool ok = false;
                    for(int i = 1 ;i<=it;i++){
                        if(frq[{x,y-i}]){
                            y-=i-1;
                            ok = true;
                            break;
                        }
                    }
                    if(ok == false){
                        y-=it;
                    }
                }
                else{
                    // left
                     bool ok = false;
                    for(int i = 1 ;i<=it;i++){
                        if(frq[{x-i,y}]){
                            x-=i-1;
                            ok = true;
                            break;
                        }
                    }
                    if(ok == false){
                        x-=it;
                    }
                }
            }
            ans = max(ans ,x*x + y*y);
        }
        return ans ;
    }
};