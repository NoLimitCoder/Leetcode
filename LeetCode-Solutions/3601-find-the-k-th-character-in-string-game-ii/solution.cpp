typedef long long ll;
class Solution {
public:
    char kthCharacter(ll k, vector<int>& A) {
        //idea: we can go back from k to n = 1 and track how many flips happened, cause in an ideal world k = a if op = [0,0,0,0,0]   
        int n = A.size();
        int flips = 0;
        vector<ll> pw2(64); pw2[0] = 1LL;
        for(ll i = 1; i <= 60; ++i){ pw2[i] = 2LL*pw2[i-1]; }
        while(k > 1){ // 0?
            for(int i = 1; i<=n; ++i){
                if(pw2[i] >= k){
                    if(A[i-1] == 1) flips++;
                    k -= pw2[i-1]; break;
                }
            }
        }
        flips%=26;
        return (char) ('a' + flips);
    }
};
