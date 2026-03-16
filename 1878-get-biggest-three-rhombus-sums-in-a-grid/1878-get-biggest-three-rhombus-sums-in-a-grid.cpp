class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        function<bool(int)>ok=[&](int me)->bool{
            if(me<0 || me >=n)
                return false;
            return true;
        };
        function<bool(int)>ok2=[&](int me)->bool{
            if(me<0 || me >=m)
                return false;
            return true;
        };
        set<int,greater<>>me;
        for(int i = 0 ; i <n ; i++){
            for(int j = 0 ; j < m ;j++){
                me.insert(grid[i][j]);
                for(int k = 1 ; k <=50 ; k++){
                    int a = i+(k-1);
                    int b = j+(k-1);
                    int c = i+((k-1)*2);
                    int d = j-(k-1);
                    if(!ok(a) or !ok(c) or !ok2(b) or !ok2(d)){
                        continue;
                    }
                    int cur = 0 ;
                    for(int from = i,from2 = j; from <=i+(k-1) ;from++,from2++){
                        cur +=grid[from][from2];
                    }
                    for(int from = i+1,from2 = j-1; from <=i+(k-1) ;from++,from2--){
                        cur +=grid[from][from2];
                    }
                    for(int from = i+(k-1),from2 = j-(k-1); from <=i+((k-1)*2) ;from++,from2++){
                        cur +=grid[from][from2];
                    }
                    for(int from = i+((k-1)*2),from2 = j; from >=i+(k-1) ;from--,from2++){
                        cur +=grid[from][from2];
                    }
                    cur -=grid[i+(k-1)][j-(k-1)];
                    cur -=grid[i+((k-1)*2)][j];
                    cur -=grid[i+(k-1)][j+(k-1)];
                    if(cur-=0)
                    me.insert(cur);
                }
            }
        }
        vector<int>ans;
        while(ans.size()!=3 ){
            if(me.size()==0)
                break;
            ans.push_back(*me.begin());
            me.erase(me.begin());
        }
        return ans ;
    }
};