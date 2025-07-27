#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:
    int minJumps(vector<int>& A) {
        int n = A.size(), mx = *max_element(A.begin(), A.end());
        vector<int> dp(mx+1);
        for(int i = 2; i<=mx; ++i) if(!dp[i]){ 
            for(int j = i; j<=mx; j+=i) if(!dp[j]) dp[j] = i;
        }
        vector<vector<int>> mp(mx+1);
        rep(i,n){
            int x = A[i];
            while(x > 1){
                int prime = dp[x]; mp[prime].push_back(i);
                while(x % prime == 0) x/=prime;
            }
        }
        vector<int> D(n,-1); queue<int> q;
        D[0] = 0; q.push(0);
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            int d_i = D[u];
            if(u+1 < n && D[u+1] < 0){D[u+1] = d_i+1; q.push(u+1);}
            if(u-1 >=0 && D[u-1] < 0){D[u-1] = d_i+1; q.push(u-1);}
            int x = A[u];
            if(dp[x] == x){
                for(int j : mp[x]){
                    if(D[j] < 0){D[j] = d_i+1; q.push(j);}
                }
                mp[x].clear();
            }
        }
        return D[n-1];
    }
};
