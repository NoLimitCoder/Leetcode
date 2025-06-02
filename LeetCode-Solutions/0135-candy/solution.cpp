class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = (int)ratings.size(); if (n < 2) return n;
        vector<int> L(n, 1), R(n, 1);
        // 1) Left→Right pass: enforce “if ratings[i]>ratings[i−1], L[i]=L[i−1]+1”
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                L[i] = L[i-1] + 1;
            }
            // else L[i] stays 1
        }
        // 2) Right→Left pass: enforce “if ratings[i]>ratings[i+1], R[i]=R[i+1]+1”
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                R[i] = R[i+1] + 1;
            }
            // else R[i] stays 1
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(L[i], R[i]);
        }
        return (int)ans;
    }
};

