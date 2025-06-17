typedef long long ll;
const int MOD = 1e9 + 7;
const int MAX = 100005;
ll fact[MAX], invfact[MAX];

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < MAX; ++i) fact[i] = fact[i - 1] * i % MOD;
    invfact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 1; --i) invfact[i] = invfact[i + 1] * (i + 1) % MOD;
}

ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

auto init = []() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); precompute(); return 0;}();

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        return m * C(n - 1, k) % MOD * power(m - 1, n - 1 - k) % MOD;
    }
};
