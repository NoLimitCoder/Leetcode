typedef vector<int> VI;
typedef vector<vector<int>> VII;

class Solution {
public:

VII M;
const int INF = 2e9;
int n;

int dp(int i, int j, int (&MEMO)[205][205]){
    if(i < 0 || j < 0 || i >= n || j >= n)
        {return INF;}
    if(i == n-1)
        {return M[i][j];}
    if(MEMO[i][j] != INF)
        {return MEMO[i][j];}
        int mn = INF;
    for(int x = 0; x<n; ++x){
        if(x == j) continue;
        int a = M[i][j] + dp(i+1,x,MEMO);
        mn = min(mn, a);
    }
    MEMO[i][j] = mn;
    return MEMO[i][j];
}

    int minFallingPathSum(vector<vector<int>>& matrix) {
        M.clear();
        M = matrix;
        n = M.size();
        int MEMO[205][205];
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                MEMO[i][j] = INF;
            }
        }
        int mn = INF;
        for(int i = 0; i<n; ++i){
            cout << mn << '\n';
            mn = min(mn, dp(0,i,MEMO));
        }

        return mn;
    }


};
