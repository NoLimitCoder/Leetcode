typedef long long ll;
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
    ll cost = max(n,m);
    if(cost < k){
        return 0;
    }
        else{
            return k*(cost-k);
        }
    }
};
