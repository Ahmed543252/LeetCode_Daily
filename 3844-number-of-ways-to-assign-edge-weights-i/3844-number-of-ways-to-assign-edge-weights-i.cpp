class Solution {
public:
const int MOD = 1e9 + 7;
const int MAXN = 100005; 

long long fact[1000005];
long long invFact[1000005];

long long power(long long base, long long exp) {
    long long res = 1;
    base = base % MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        precompute();
        int m = edges.size();
        vector<int>dep(m+2,0);
        vector<int>adj[m+2];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int mx_dep = 0;
        function<void(int , int )>dfs=[&](int node, int par){
            for(auto it : adj[node]){
                if(it == par)
                    continue;
                dep[it]=dep[node]+1;
                dfs(it, node);
                mx_dep=max(mx_dep,dep[it]);
            }
        };
        dfs(1,-1);
        int cnt = 0;
        for(int i =1 ; i<=m+1;i++ ){
            if(dep[i]==mx_dep){
                cnt++;
            }
        }
        int res = 0;
        for(int i = 1; i<=mx_dep ;i+=2){
            int cur = nCr(mx_dep,i);
            res = (res + cur)%MOD;
        }
        // res = power(res,cnt);
        return res;
    }
};