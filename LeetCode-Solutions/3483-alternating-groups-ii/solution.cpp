class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& A, int k) {
        int cnt = 0, l = 0;
        A.insert(A.end(), A.begin(), A.begin() + (k - 1));
        for (int r = 0; r < A.size(); ++r) {
            if (r > 0 && A[r] == A[r - 1]) { l = r; }
            if (r - l + 1 >= k) { cnt++; }
        }
        return cnt;   
    }
};
