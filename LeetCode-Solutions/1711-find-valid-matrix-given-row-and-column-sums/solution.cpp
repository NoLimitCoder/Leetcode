auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
typedef vector<int> VI; typedef vector<vector<int>> VVI;
class Solution {
public:
    static vector<vector<int>> restoreMatrix(vector<int>& R, vector<int>& C) {
        int n = R.size(), m = C.size(); VVI A(n, VI(m, 0));
        for (int i = 0, j = 0; i<n && j<m ; i += (R[i] == 0), j += (C[j] == 0))
            { int x = min(R[i], C[j]); A[i][j] = x; R[i] -= x; C[j] -= x; }
        return A;
    }
};
