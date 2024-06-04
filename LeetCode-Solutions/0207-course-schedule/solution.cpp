class Solution {
public:

int n;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool no_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;
    cycle_end = -1;
    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }
    if (cycle_start == -1) {
        return true;
    }
    return false;
}


    bool canFinish(int N, vector<vector<int>>& A) {
        n = N;
        adj = vector<vector<int>>(N);
        for(int i=0;i<A.size();i++){
            int u=A[i][0], v=A[i][1];
            adj[v].push_back(u);
        }
    return no_cycle();
    }
};
