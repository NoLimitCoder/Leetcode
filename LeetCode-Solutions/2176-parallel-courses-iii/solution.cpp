typedef long long ll;
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        for (auto& r : relations) { int u = r[0] - 1, v = r[1] - 1; adj[u].push_back(v); }
        vector<char> vis(n, 0);
        vector<int> order;
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1; for (int v : adj[u]) if (!vis[v]) dfs(v);
            order.push_back(u);
        };
        for (int i = 0; i < n; ++i) if (!vis[i]) dfs(i);
        reverse(order.begin(), order.end());
        vector<ll> dp(n, 0);
        ll answer = 0;
        for (int u : order) {
            dp[u] += time[u];
            answer = max(answer, dp[u]);
            for (int v : adj[u]) {
                dp[v] = max(dp[v], dp[u]);
            }
        }
        
        return answer;
    }
};

