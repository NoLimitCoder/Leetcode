#pragma GCC optimize("O3,unroll-loops")

class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int k) {
        int odd = 0, max_odd = 0, ans = 0, mp[50001] = {};
        for(int cur : A){ if(cur&1) {odd++; max_odd = max(max_odd, odd);}  mp[odd]++; }
        for(int count = k; count <= max_odd; ++count){ ans += (mp[count-k] * mp[count]); }
        return ans + mp[k];
    }
};
