class Solution {
public:
    const int mod = 1e9 + 7;
    int valueAfterKSeconds(int n, int k) {
        int sum = 0;
        vector<int> P(n,1);
        for(int i = 0; i<k; ++i){
            for(int j = 0; j<n; ++j){
                if(j == 0) continue;
                P[j] = P[j] + P[j-1];
                P[j] %= mod;
            }
        }
        return P[n-1];
    }
};
