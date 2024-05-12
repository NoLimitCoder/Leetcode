class Solution {
public:

    int findMax(vector<vector<int>>& grid, int r, int c){
        int mx = 0;
        for(int i = r; i < r+3; ++i){
            for(int j = c; j < c+3; ++j){
                mx = max(mx, grid[i][j]);
            }
        }
        return mx;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        for(int i = 0; i<n-2; ++i){
            for(int j = 0; j<n-2; ++j){
                ans[i][j] = findMax(grid, i, j);
            }
        }
        return ans;
    }
};
