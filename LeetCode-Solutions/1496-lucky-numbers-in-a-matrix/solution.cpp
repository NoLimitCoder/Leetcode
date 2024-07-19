auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
const int INF = 1e5+1;
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        vector<int>r(m,INF), c(n,-INF), ans;
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                r[i] = min(r[i], M[i][j]);
                c[j] = max(c[j], M[i][j]);
            }
        }
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(M[i][j] == r[i] && M[i][j] == c[j]) ans.push_back(M[i][j]);
            }
        }
        return ans;
    }
};
