typedef long long ll;
class Solution {
const ll INF = 1e9;
public:

vector<int> C;
    ll MEMO[10005];
    //dp[i] = minimum number of coins needed to make sum i
    ll dp(ll sum){
        //base case
        if(sum == 0){return 0;}
        //invalid case
        if(sum < 0){return INF;}

        if(MEMO[sum] != -1){
            return MEMO[sum];
        }

        ll mn = INF;
        for(int c : C){
            //choice 1 take the element
            mn = min(mn, 1 + dp(sum-c));
            //option 2 not take element
            continue;
        }
        MEMO[sum] = mn;
        return mn;
    }
    int coinChange(vector<int>& coins, int amount) {
     /*
        C = coins;
        for(int i = 0; i<10005; ++i){
            MEMO[i] = -1;
        }
        ll answer = dp(amount);
        return (answer>=INF)? -1 : answer;*/

        //dp[i] is mininmum change needed to make sum i
        int dp[amount+1];
        for(int i = 1; i<=amount; ++i){
            dp[i] = INF;
        }
        dp[0] = 0;
        for(int current_sum = 1; current_sum <= amount; current_sum++){
            for(int c : coins){
                if(current_sum - c < 0) continue;
                dp[current_sum] = min(dp[current_sum], 1 + dp[current_sum - c]);
            }
        }
        return (dp[amount]>=INF-10)? -1 : dp[amount];
    }
};
