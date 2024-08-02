auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:
    int minimumDeletions(string s) {
        //proof for why prefix / suffix works
        /*idea: optimal answer has to be of the form an | bm
        the given problem appends noise to the optimal answer, making it an+x | bm+y
        where x denotes the number of noisy Bs in the a subpart and y denotes the number of noisy As in the b subpart
        
        Approach: if we can guess the number of As in the optimal answer, then we know 2 things for certain
        1. they must be the first n a's in the sequence since all the b's up till that point must be noise x
            given that the problem structure enforces an | bm, thus any b found within the first n a's is part of the noise
        2. If we guess n, we're also guessing x and y, and if we find x, then we also find m, since x is the number of noisy b's in the sequence
            and total number of b's = bm + x, while total number of a's = an + y

        what does that mean? it means if we know there are n a's in the answer, then we know they must be the first n a's and the remaining a's in 
        the sequence are noise, similarly any b found up until the point where we reach the first n a's must be noise since there is no other way
        of reaching the first n a's than by going through them, and if we know how many noisy b's there are, then we can also know
        how many b's there are in the optimal answer since total number of b's = b's in optimal answer + noisy b's
        
        therefore the problem we're solving reduces to finding the index i that has the first n a's
        where we claim that the optimal solution must have n a's, and n is the number we're trying to guess
        so we just take the minimun value we find across selecting all possible values of n which has to be <= to total number of a's
        */

/*
        //compute noise suffix for a's
        int y = 0; for(char c : s){ y += c=='a'; }
        //compute noise for b's as prefix and calculate answer
        int x = 0, ans = x+y;
        for(char c : s){
            c=='a'? --y : ++x;
            //guess this to be the right value of n, thus x and y are both noise (we could put an if to only compute min if the current letter is a but its not necessary)
            //if(c=='a') 
            ans = min(ans, x+y);
        }
        return ans;
*/
    //dp solution
    int n = s.size();
    int dp[n][2]; // dp[i][0] -> xxxxa  |  dp[i][1] -> xxxxb
    memset(dp,0,sizeof(dp));
    dp[0][0] += (s[0]=='b');
    dp[0][1] += (s[0]=='a');
    for(int i = 1; i<n; ++i){
        if(s[i] == 'a'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + 1;
        }else {
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = min(dp[i-1][1], dp[i-1][0]);
        }
        //cout  << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    return min(dp[n-1][0], dp[n-1][1]);
  }
};
