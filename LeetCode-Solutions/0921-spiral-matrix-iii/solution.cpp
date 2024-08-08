auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int r, int c, int r0, int c0) {
        int lr = 1, d = 0; vector<vector<int>> ans;
        while(ans.size() < r * c){
            rep(i,2){
                rep(j,lr){
                    if(r0 >= 0 && r0 < r && c0 >= 0 && c0 < c){ ans.push_back({r0, c0}); }
                    r0 += dx[d]; c0 += dy[d];
                }
                d+=1; d%=4;
            }
            ++lr;
        }
        return ans;
    }
};
