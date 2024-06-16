#pragma GCC optimize("O3,unroll-loops")
auto init = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return'c';}();
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0, i = 0;
        long long r = 0;
        while(i < nums.size() && r < n){
            if(nums[i]<=r+1) r+=nums[i];
            else{
                while(r+1 < nums[i] && r < n)
                    {ans++; r += (r+1);}
                r+=nums[i];
            }
            ++i;
        }
        while(r < n)
            {ans++; r += (r+1);}
        return ans;
    }
};
