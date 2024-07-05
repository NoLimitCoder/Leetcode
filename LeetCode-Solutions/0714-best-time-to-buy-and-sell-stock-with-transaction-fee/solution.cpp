#pragma GCC optimize("O3,unroll-loops")
typedef vector<int> VI; typedef vector<VI> VVI;
class Solution {
public:
/*
    int maxProfit(int i, bool state, VI&P, int &fee, VVI &DP){
        if(i == P.size()) return 0;         if (DP[i][state]) return DP[i][state];
        int res1; if(state)  res1 =  P[i] -  fee + maxProfit(i+1,!state,P,fee,DP); //if we have a stock, choose to sell it
                  else       res1 = -P[i] -   0  + maxProfit(i+1,!state,P,fee,DP); //if we don't have a stock, choose to buy it    
        int res2;            res2 =   0   -   0  + maxProfit(i+1, state,P,fee,DP); //for both cases, also choose to not do anything and go to the next index
        return DP[i][state] = max(res1,res2);
    }*/
    int maxProfit(vector<int>& P, int fee) {
        //VVI DP(P.size()+1, VI(2,0));
        // return maxProfit(0,0,P,fee,DP);
        int dp_next_0 = 0, dp_next_1 = 0, dp_cur_0 = 0,dp_cur_1 = 0;
        for(int i = P.size()-1; i>=0; --i){
            //DP[i][1] = max(DP[i+1][1], P[i]-fee + DP[i+1][0]);
            //DP[i][0] = max(DP[i+1][0], -P[i] + DP[i+1][1]);
            dp_cur_1 = max(dp_next_1, P[i]-fee + dp_next_0);
            dp_cur_0 = max(dp_next_0, -P[i] + dp_next_1);
            dp_next_0 = dp_cur_0; dp_next_1 = dp_cur_1;
        }
        return dp_cur_0;
    }      
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
