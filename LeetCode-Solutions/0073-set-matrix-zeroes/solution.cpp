class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        vector<pair<int,int>>V;
        int n = A.size(), m = A[0].size();
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(A[i][j] == 0) V.push_back({i,j});
            }
        }
        for(auto &[r,c] : V){
            for(int j = 0; j<m; ++j){
                A[r][j] = 0;
            }
            for(int i = 0; i<n; ++i){
                A[i][c] = 0;
            }
        }
    }
};
