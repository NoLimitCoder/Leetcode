auto init = [](){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj; 
        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            adj[u].push_back({w,v});
        }
        queue<pair<int,int>> q; q.push({0,src});
        vector<int> D(n,INT_MAX); D[src]=0;    
        while(!q.empty() && k-- >= 0){
        int l = q.size();
            while(l--){
                auto [d, u] = q.front(); q.pop();
                for(auto [w, v] : adj[u]){
                    if(D[v] > d+w){
                        D[v] = d+w;
                        q.push({D[v],v});
                    }
                }
            }
        }
        return D[dst] == INT_MAX? -1 : D[dst];
    }
};
