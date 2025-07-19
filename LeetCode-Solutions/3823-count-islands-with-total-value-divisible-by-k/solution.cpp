int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
#define rep(i,n) for(int i = 0; i<n; ++i)
typedef long long ll;
class Solution {
public:
    int countIslands(vector<vector<int>>& g, int k) {
        int m = g.size(), n = g[0].size();
        int ans = 0;
        vector<pair<int,int>>st;
        rep(i,m){
            rep(j,n){
                if(!g[i][j]) continue;
                ll sum = 0; st.clear(); st.emplace_back(i,j);
                sum+=g[i][j]; g[i][j] = 0;
                while(!st.empty()){
                    auto [x,y] = st.back(); st.pop_back();
                    for(int d = 0; d<4; ++d){
                        int nx = x+dx[d], ny = y+dy[d];
                        if(nx >= 0 && nx < m && ny>=0 && ny<n && g[nx][ny]){
                            sum += g[nx][ny]; st.emplace_back(nx,ny); g[nx][ny] = 0;
                        }
                    }
                }
                if(sum%k == 0) ++ans;
            }
        }
        return ans;
    }
};
