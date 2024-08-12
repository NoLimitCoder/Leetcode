#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '
typedef long long ll;
const ll INF = 4e18;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int countOfPairs(vector<int>& A) {
        //dp[i][j] -> at position i in both arrays, using number j in array1 and k in array2
        //pull the number of ways of the vaild states we can reach
        int n = A.size(), m = *max_element(A.begin(), A.end());
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i = 0; i<=A[0]; ++i) dp[0][i] = 1;
        vector<int> P(m+5);
        for(int i = 1; i<n; i++){
            vector<int> P(m+5,0);
            for(int l = 0; l <= A[i]; ++l) { P[l]+=dp[i-1][l]; if(l) P[l] += P[l-1]; P[l]%=MOD;}
            for(int j = A[i]; j >= 0; j--){          
                int k = A[i]-j-1;
                int r = min(j+1, A[i-1]-k);
               // deb(r);
                //for(int x = 0; x < r; x++){    //x < j+1 && x < A[i-1]-k;
                    //dp[i][j] += dp[i-1][x]; dp[i][j] %= MOD;
                    if(r>0)dp[i][j] += P[r-1]; dp[i][j] %= MOD;
                    
                  //  debl(x); cout << "-> " << dp[i-1][x] << ' '; 
                //} //deb(P[r-1]); //cout << '\n'; 
            }
        }
        int ans = 0;
        for(int j = 0; j<=m; ++j)
            { ans += dp[n-1][j]; ans %= MOD; }
        return ans;
    }
};
