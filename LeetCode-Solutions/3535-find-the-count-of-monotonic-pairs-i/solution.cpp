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

        for(int i = 1; i<n; i++){
            for(int j = A[i]; j >= 0; j--){          //A[i]          -> j -> arr1
                int k = A[i]-j;                      //A[i]  - j     -> k -> arr2
                for(int x = 0; x <= A[i-1]; x++){   //A[i-1]         -> x -> arr1
                    int y = A[i-1]-x;               //A[i-1] - x     -> y -> arr2
                    if(x <= j && y >= k) dp[i][j] += dp[i-1][x];
                    dp[i][j] %= MOD;
                }
            }
        }
        int ans = 0;
        for(int j = 0; j<=m; ++j)
            { ans += dp[n-1][j]; ans %= MOD; }
        return ans;
    }
};
