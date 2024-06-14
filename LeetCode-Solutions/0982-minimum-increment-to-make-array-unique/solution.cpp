#pragma GCC optimize("O3,unroll-loops")
//EDUCATIONAL PURPOSES
const int MAXN = 1e5+5;
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int mp[MAXN] = {};
        int mx = 0;
        for(int i = 0; i<nums.size(); ++i){
            mp[nums[i]]++;
            mx = max(mx, nums[i]);
        }
        int ans = 0;
        int last = 0;
        for(int i = 0; i<=mx+1; ++i){
            if(mp[i] != 0){last = i;}
            int offset = max(0, mp[i] -1);
            ans += offset;
            mp[i+1] += offset;
        }
        return ans + ((mp[last]-2) * (mp[last]-1))/2;
    }
/*
    123456789
1234555555555
Gaussian = (n-1*(n-2))/2 summation 
*/


};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
