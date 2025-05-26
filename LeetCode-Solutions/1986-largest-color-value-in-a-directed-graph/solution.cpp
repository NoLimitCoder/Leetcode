class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(); vector<vector<int>> adj(n); vector<int> indegree(n);
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); indegree[e[1]]++; }
        queue<int> q; int flag = 0, ans = 0;
        for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);
        vector<array<int,26>> dp(n); for (int i = 0; i < n; i++) dp[i].fill(0);
        while (!q.empty()) {
            int u = q.front(); q.pop(); ++flag;
            int c = colors[u] - 'a'; dp[u][c]++; ans = max(ans, dp[u][c]);
            for (int v : adj[u]) {
                for (int k = 0; k < 26; k++) dp[v][k] = max(dp[v][k], dp[u][k]);
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return flag == n ? ans : -1;
    }
};
