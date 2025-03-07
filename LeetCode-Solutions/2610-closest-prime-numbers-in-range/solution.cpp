#pragma GCC optimize(O3,"unroll-loops")
const int MAXN = 1e6 +1;
vector<int> sieve(MAXN,1);

auto init = []() { 
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //sieve initialization
    sieve[1] = 0; 
    for(long long i = 2; i*i<MAXN; ++i) if(sieve[i]){
        for(long long j = i*i; j<MAXN; j+=i){
            sieve[j] = 0;
        }
    }
    return 0; 
}();

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = {-1,-1}; 
        int idx = 0, prev = 0, dif = 1e7;
        for(int i = left; i <= right; ++i){
            if(sieve[i] && prev == 0) prev = i;
            else if(sieve[i]){
                if(i-prev < dif){
                    dif = i-prev;
                    ans = {prev, i};
                }
                prev = i;
            }
        }
        return ans;
    }
};
