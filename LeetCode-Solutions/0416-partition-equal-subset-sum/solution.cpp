#define rep(i,n) for(int i = 0; i<n; ++i)
#define deb(x) cout << #x << ": " << x << '\n'
class Solution {
public:

bool f(int idx, int sum, vector<int>& A, vector<vector<int>>&DP){
    if(sum == 0) return 1;
    if(idx >= A.size() || sum < 0) return 0;
    if(DP[idx][sum] != -1) return DP[idx][sum];
    //decision take or not take
    bool r1 = f(idx+1, sum,A,DP); //not take
    bool r2 = f(idx+1, sum - A[idx],A,DP); //not take
    return DP[idx][sum] = r1 || r2;
}


    bool canPartition(vector<int>& A) {
        int sum = 0, n = A.size();
        for(int i = 0; i<n; ++i){ sum += A[i]; }
        if(sum&1) return 0; sum/=2;
        //0/1 knapsack of possibility
        //state-> using a subset up till index i what is possible at money j
        /*vector<vector<bool>>DP(n+1, vector<bool>(sum+1,0));
        DP[0][0] = 1; //we'll start at index 1 for dp
        for(int i = 1; i<=n; ++i){
            for(int j = 0; j<=sum; ++j){
                //not take -> propagate value from previous subproblem
                DP[i][j] = DP[i-1][j];
                //take -> substract our value from sum and if there's a path in the previous subproblem to 0 then this number is also valid
                if(j-A[i-1] >= 0) DP[i][j] = (DP[i][j] || DP[i-1][j-A[i-1]]);
            }
        }*/
        vector<vector<int>>DP (n+1, vector<int>(sum+1,-1));
        return f(0,sum,A, DP);
    }
};
