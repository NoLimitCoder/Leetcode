
class Solution {
public:
    int minDifference(vector<int>& A) {
        int n = A.size();
        if(n <= 4) return 0;
        sort(A.begin(), A.end()); 
        int ans = A[n-1] - A[0];
        for(int i = 3; i>=0; --i){
            ans = min(ans, A[n-i-1] - A[3-i]);
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
