#define deb(x) cout << #x << ": "<< x << '\n'
#define debl(x) cout << #x << ": "<< x << ' '
auto init = []() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
class Solution {
public:

    void BFS(int src, vector<vector<int>>&AL, vector<int> &odds, vector<int> &evens){
        queue<int>q; vector<int>D(AL.size()+1,-1);
        q.push(src); D[src] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(D[u]%2 == 0) {evens.push_back(u);}
            else {{odds.push_back(u);}}
            for(int v : AL[u]){
                if(D[v] == -1) {D[v] = D[u]+1; q.push(v); }
            }
        }
    }

        vector<int> maxTargetNodes(vector<vector<int>>& E1, vector<vector<int>>& E2) {
        int n = E1.size()+1, m = E2.size()+1, mx = 0;
        vector<vector<int>>AL1(n+1, vector<int>()), AL2(m+1, vector<int>());
        for(auto it : E1)
            { int u = it[0], v = it[1]; AL1[u].push_back(v); AL1[v].push_back(u); }
        for(auto it : E2)
            { int u = it[0], v = it[1]; AL2[u].push_back(v); AL2[v].push_back(u); }
        //invariants to calculate prices
        vector<int>odds1, evens1, odds2, evens2;
        BFS(0,AL1,odds1,evens1); BFS(0,AL2,odds2,evens2);
        int evens = evens2.size(), odds = odds2.size();
        vector<int>ans(n);
        //deb("odds");
        for(int i : odds1){
            //deb(i);
            ans[i] = odds1.size() + max(evens,odds);
        }
        //deb("evens");
        for(int i : evens1){
            //deb(i);
            ans[i] = evens1.size() + max(evens,odds);
        }
        return ans;
    }
    //odd           even
    //0
    // 2 3 1 5 6 = 6 | 0 7 4 = 3
    //2
    //7 0 4 = 3 | = 2 3 1 5 6 = 6
 };
