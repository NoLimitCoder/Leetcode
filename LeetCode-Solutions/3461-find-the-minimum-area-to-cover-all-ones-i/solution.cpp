#define deb(x) cout <<x.first << ' ' << x.second << '\n'
class Solution {
public:
    int minimumArea(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        int u = 2e9, d = -1, l= 2e9, r= -1;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(A[i][j] == 1 && i < u) u = i;
                if(A[i][j] == 1 && i > d) d = i;
                if(A[i][j] == 1 && j < l) l = j;
                if(A[i][j] == 1 && j > r) r = j;
            }
        }
        return (d-u+1) * (r-l+1);
        //return 0;
    }
};
