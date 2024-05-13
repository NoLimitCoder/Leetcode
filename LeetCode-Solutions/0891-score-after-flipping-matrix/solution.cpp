class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> mp(n);
        for(int i = 0; i < m; ++i){
            bool flag = (grid[i][0] == 0);
            for(int j = 0; j < n; ++j){
                if(flag) grid[i][j] ^= 1;
                if(grid[i][j] == 1) mp[j]++;
            }
        }
        for(int i = 0; i < n; ++i)
            {ans += (1<<(n-i-1)) * max(mp[i], m-mp[i]);}
        return ans;
    }
    
};
