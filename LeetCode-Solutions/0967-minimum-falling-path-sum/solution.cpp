typedef vector<int> VI;
typedef vector<vector<int>> VII;

class Solution {
public:

VII M;
const int INF = 2e9;
int n;

int dp(int i, int j, int (&MEMO)[105][105]){
    if(i < 0 || j < 0 || i >= n || j >= n)
        {return INF;}
    if(i == n-1){
        return M[i][j];
    }
    if(MEMO[i][j] != INF){
        return MEMO[i][j];
    }
    //add current sum to range.
    //explore directions
    int a = M[i][j] + dp(i+1,j-1,MEMO);
    int b = M[i][j] + dp(i+1,j,MEMO);
    int c = M[i][j] + dp(i+1,j+1,MEMO);
    int mn = min({a,b,c});
    MEMO[i][j] = mn;
    return MEMO[i][j];
}

    int minFallingPathSum(vector<vector<int>>& matrix) {
        M.clear();
        M = matrix;
        n = M.size();
        int MEMO[105][105];
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                MEMO[i][j] = INF;
            }
        }/*
                for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                cout << MEMO[i][j] << ' ';
            } cout << '\n';
        }*/
        int mn = INF;
        for(int i = 0; i<n; ++i){
            cout << mn << '\n';
            mn = min(mn, dp(0,i,MEMO));
            //cout << mn << '\n';
        }
        /*for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                cout << MEMO[i][j] << ' ';
            } cout << '\n';
        }*/
        /*
           for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                cout << M[i][j] << ' ';
            } cout << '\n';
        }*/

        return mn;
    }


};
