auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
const int MOD = 1e9 + 7;
class Solution {
public:
    int countOfPairs(vector<int>& A) {
        /* idea:
            dp[i][j] -> at position i in both arrays, using number j in array1 and k in array2
            pull the number of ways of the vaild states we can reach */
        
        //initialize variables
        int n = A.size(), m = *max_element(A.begin(), A.end());
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        //setup base cases
        for(int i = 0; i<=A[0]; ++i) dp[0][i] = 1;
        //dp
        for(int i = 1; i<n; i++){
            //compute prefix sums of state i
            vector<int> P(m+1); 
            for(int l = 0; l <= A[i]; ++l){
                P[l] += dp[i-1][l]; if(l) P[l] += P[l-1]; P[l] %= MOD; 
            }
            //pull from valid states
            for(int j = A[i]; j >= 0; j--){ //j -> arr1
                int k = A[i]-j;             //k -> arr2
                //compute upper_bound of valid states
                int r = min(j, A[i-1]-k); //do some math on paper to find this upper_bound
                //optimized, using prefix sum O(1)
                if(r >= 0) { dp[i][j] += P[r]; dp[i][j] %= MOD; }
            }
        }
        int ans = 0;
        for(int j = 0; j<=m; ++j)
            { ans += dp[n-1][j]; ans %= MOD; }
        return ans;
    }
};
