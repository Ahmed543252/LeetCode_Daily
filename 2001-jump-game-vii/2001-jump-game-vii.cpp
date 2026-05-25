class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1]=='1')
        return false;
        queue<int>q;
        q.push(0);
        int far = 0 ;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(top == n-1){
                return true;
            }
            int start = max(top+minJump,far+1);
            int end = min(n-1 , top+maxJump);
            for(int i = start ; i<=end;i++){
                if(s[i]=='0'){
                    q.push(i);
                }
            }
            far = max(far, top+maxJump);
        }
        return false;
    }
};