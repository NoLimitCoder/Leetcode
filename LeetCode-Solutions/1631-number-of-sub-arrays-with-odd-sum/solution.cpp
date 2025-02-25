#pragma GCC optimize(O3,"unroll-loops")
auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
const int MOD = 1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), odd = 0, even = 1, ans = 0, p = 0;
        for(int i = 0; i<n; ++i){
            p += arr[i]; p %= 2;
            if(p&1) { odd++;  ans += even; }
            else    { even++; ans += odd ; }
            ans %= MOD;
        }
        return ans;
    }
};
