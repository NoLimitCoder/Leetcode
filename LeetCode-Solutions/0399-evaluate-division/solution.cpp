#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& qr) {
        unordered_map<string,int> var_map;
        int id_cnt = 0, m = eq.size();
        rep(i,m){
            if(!var_map.count(eq[i][0])) var_map[eq[i][0]] = id_cnt++;
            if(!var_map.count(eq[i][1])) var_map[eq[i][1]] = id_cnt++;
        }
        
        vector<vector<pair<int,double>>> adj(id_cnt);
        rep(i,m){
            int a = var_map[eq[i][0]];
            int b = var_map[eq[i][1]];
            double w = val[i];
            adj[a].push_back({b, w});
            adj[b].push_back({a, 1.0/w});
        }
        
        int Q = qr.size();
        vector<double> ans(Q);
        rep(i,Q){
            auto &p = qr[i];
            if(!var_map.count(p[0]) || !var_map.count(p[1])){
                ans[i] = -1; continue;
            }
            int s = var_map[p[0]], t = var_map[p[1]];
            if(s==t){ ans[i] = 1; continue; }
            
            vector<char> vis(id_cnt);
            queue<pair<int,double>> q;
            q.push({s,1});
            vis[s] = 1;
            
            double res = -1;
            while(!q.empty()){
                auto [u, prod] = q.front(); q.pop();
                for(auto &e: adj[u]){
                    int v = e.first;
                    if(vis[v]) continue;
                    double np = prod * e.second;
                    if(v==t){ res = np; break; }
                    vis[v] = 1;
                    q.push({v,np});
                }
                if(res>0) break;
            }
            ans[i] = res;
        }
        return ans;
    }
};

