class Solution {
public:
    int maxProfit(vector<int>& A) {
        int mx = 0, n = A.size();
        vector<int> suf = A;
        for(int i = n-2; i>=0; --i){suf[i] = max(suf[i], suf[i+1]);}
        for(int i = 0; i<n; ++i){
            mx = max(mx, suf[i] - A[i]);
        }
        return mx;
    }
};
