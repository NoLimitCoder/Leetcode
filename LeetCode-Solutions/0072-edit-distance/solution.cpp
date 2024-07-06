auto init = [](){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size(), DP[505][505];
        rep(i,n+1) rep(j,m+1) DP[i][j] = 0;
        //base cases  pad everything by 1 because we can not reference idx = -1
        DP[0][0] = 0;
        rep(i,n+1) DP[i][0] = i;
        rep(j,m+1) DP[0][j] = j;
        //compute
        for(int i = 1; i<=n; ++i)
            for(int j = 1; j<=m; ++j){
                //transitions:
                //1 first one is the best because it gives us 0 distance, if we can reach that we should take it
                int r0 = (s1[i-1] == s2[j-1])? DP[i-1][j-1] : 1e4;
                //2 remove from 1 / append at 2
                int r1 = 1 + DP[i-1][j];
                //3 remove from 2 / append at 1
                int r2 = 1 + DP[i][j-1];
                //4 replace s1[i] with s2[j] / s2[j] with s1[i]
                int r3 = 1 + DP[i-1][j-1];
                DP[i][j] = min({r0,r1,r2,r3});
            }
            return DP[n][m];
    }
};
