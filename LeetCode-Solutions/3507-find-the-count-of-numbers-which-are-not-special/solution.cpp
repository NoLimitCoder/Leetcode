auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int l1 = ceil(sqrt(l)), r1 = sqrt(r);
        //sieve of erasthotenes
        vector<bool> is_prime(r1+5, 1);
        is_prime[0] = is_prime[1] = 0;
        for (int i = 2; i <= r1; i++) {
            if (is_prime[i] && (long long)i * i <= r1) {
                for (int j = i * i; j <= r1; j += i)
                    is_prime[j] = 0;
            }
        }
        int ans = 0;
        for(int i = l1; i<=r1; ++i){ if(is_prime[i]) {++ans;} }
        return r-l-ans+1;
    }
};
