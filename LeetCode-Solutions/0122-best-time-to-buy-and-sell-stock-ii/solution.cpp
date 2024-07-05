auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int maxProfit(vector<int>& P) {
        int dp_next_0 = 0, dp_next_1 = 0, dp_cur_0 = 0, dp_cur_1 = 0;
        for(int i = P.size()-1; i>=0; --i){
            dp_cur_1 = max(P[i]  + dp_next_0, dp_next_1);
            dp_cur_0 = max(-P[i] + dp_next_1, dp_next_0);
            dp_next_0 = dp_cur_0; dp_next_1 = dp_cur_1;
        }
        return dp_cur_0;
    }
};
