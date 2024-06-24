class Solution {
public:
    int minKBitFlips(vector<int>& A, int k) {
        int cur = 0, ans = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (i >= k && A[i - k] > 1) {cur--; A[i - k] -= 2;}
            if (cur % 2 == A[i]) { if (i + k > n) return -1; A[i] += 2; cur++; ans++;}
        }
        return ans;
    }
};
