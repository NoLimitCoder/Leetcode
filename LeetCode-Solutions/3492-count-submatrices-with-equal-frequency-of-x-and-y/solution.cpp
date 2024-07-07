#define fi first
#define se second

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int,int>>>DP(n+1, vector<pair<int,int>>(m+1,{0,0}));
        for(int i = 0; i<n; ++i){
            //first push the row, then merge and compare
            for(int j = 0; j<m; ++j){
                if(grid[i][j] == 'X') DP[i][j].fi += 1;
                if(grid[i][j] == 'Y') DP[i][j].se += 1;
                //if(DP[i][j].fi == DP[i][j].se && DP[i][j].fi > 0) ans++;
                //push
                //push to right only
                DP[i][j+1].fi += DP[i][j].fi; DP[i][j+1].se += DP[i][j].se;
                //to compute submatrix take from above
            }
            //pull from above and compare
            for(int j = 0; j<m; ++j){
                //pull
                if(i-1 >=0)
                    {DP[i][j].fi += DP[i-1][j].fi; DP[i][j].se += DP[i-1][j].se;}
                //compare
                if(DP[i][j].fi == DP[i][j].se && DP[i][j].fi > 0) ans++;
            }
        }
        return ans;
    }
};
