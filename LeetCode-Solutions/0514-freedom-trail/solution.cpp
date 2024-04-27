class Solution {
public:
    //int DP[200][200];
    int dfs(int ring_idx, int key_idx, string &ring, string &key, int &n, int &m, vector<vector<int>> &DP){
        if(key_idx == m) return 0;
        if(DP[ring_idx][key_idx] != -1){ return DP[ring_idx][key_idx];}
        //explore all possibilities in our ring for both clockwise 0+idx and counter clockwise n-idx
        int ans = INT_MAX;
        for(int i = 0; i<n; ++i){
            if(ring[i] == key[key_idx]){
                int distance = min( abs(ring_idx-i), n-abs(ring_idx - i) );
                ans = min(ans, dfs(i, key_idx+1, ring, key, n, m, DP) + distance);
            }
        }
        return DP[ring_idx][key_idx] = ans+1;
    }

    int findRotateSteps(string &ring, string &key) {
        int n = ring.size();
        int m = key.size();
        int mx = max(n,m);
        vector<vector<int>> DP(mx, vector<int>(mx,-1));
        return dfs(0,0,ring,key,n,m,DP);
    }
};
