class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& B, int n) {
        vector<int> df(n+5);
        for(int i = 0; i<B.size(); ++i){
            df[ B[i][0] ] += B[i][2];
            df[ B[i][1]+1 ] -= B[i][2];
        }
        vector<int>ans(n);
        for(int i = 1; i<=n; ++i){
            df[i] += df[i-1];
            ans[i-1] = df[i];
        }
        return ans;
    }
    
};
