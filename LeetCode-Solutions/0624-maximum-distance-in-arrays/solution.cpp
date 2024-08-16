auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    int maxDistance(vector<vector<int>>& A) {
        int n = A.size(), mx1 = INT_MIN, mx2 = INT_MIN, y = -1, ans = 0;
        for(int i = 0; i<n; ++i){
            int mx = A[i][A[i].size()-1];
            if      (mx > mx1) {mx2 = mx1; mx1 = mx; y = i;}
            else if (mx > mx2) {mx2 = mx;}
        }
        for(int i = 0; i<n; ++i){
            if(i == y) ans = max(ans, abs(mx2 - A[i][0]));
            else       ans = max(ans, abs(mx1 - A[i][0]));
        }
        return ans;
    }
};
