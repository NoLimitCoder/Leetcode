class Solution {
public:
    int maxLen(int n, vector<vector<int>>& E, string label) {
        //dp with bitmask? n == 14 so 1<<14 works
        //dp[i][j] = 1 if path covers i to j
        //dp[i][j][mask] = 1 if path covers i to j using mask nodes
        vector<vector<int>> AL(n);
        for(auto e : E){
            AL[e[0]].push_back(e[1]);
            AL[e[1]].push_back(e[0]);
        }
        int MAXM = (1<<n), ans = 1;
        vector dp(MAXM, vector(n, vector<bool>(n,0)));
        for(int u = 0; u<n; ++u) dp[1<<u][u][u] = 1;
        for(auto e : E) if(label[e[0]] == label[e[1]]){
            int m = (1<<e[0]) | (1 << e[1]);
            dp[m][e[0]][e[1]] = 1;
            ans = 2;
        }
        //order: mask to i to j => if mask >> i && mask >> j && dp[mask][i][j]
        for(int mask = 1; mask < MAXM; ++mask){
            int p = __builtin_popcount(mask);
            for(int i = 0; i<n; ++i) if(mask & (1<<i) ){
                for(int j = 0; j<n; ++j) if( mask & (1<<j)){
                    if(dp[mask][i][j] != 0){
                       /* if(i==j){
                            for(int x : AL[i]) if((mask & (1<<x)) == 0){
                                int m = mask | (1<<x);
                                if(!dp[m][x][x]){dp[m][x][x] = 1; ans = max(ans,p+1);}
                            }
                        }*/
                        //cout << dp[mask][i][j] << '\n';
                        for(int x : AL[i]) if( (mask&(1<<x)) == 0){
                            for(int y : AL[j]) if( (mask&(1<<y)) == 0){
                                if(x!=y && label[x] == label[y]){
                                    if(x==y) continue;
                                    int m = mask | (1<<x) | (1<<y);
                                    if(!dp[m][x][y]){dp[m][x][y] = 1; ans = max(ans, p+2);}
                                }
                            }
                        }
                    }
                }
            }
        }
            return ans;
    }
};
