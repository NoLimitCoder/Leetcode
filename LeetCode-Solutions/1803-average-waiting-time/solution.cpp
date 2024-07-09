auto init = [](){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& A) {
        int n = A.size(), start_time = 0;
        double ans = 0;
        for(int i = 0; i<n; ++i){
            start_time = max(start_time, A[i][0]);
            ans += start_time + A[i][1] - A[i][0];
            start_time = start_time + A[i][1];
        }
        return ans/n*1.0;
    }
};
