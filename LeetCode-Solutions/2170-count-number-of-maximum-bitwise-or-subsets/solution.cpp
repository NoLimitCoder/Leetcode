auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), N = (1<<n), y = 0, ans = 0;
        for(int i = 0; i<n; ++i){y |= nums[i];}
        for(int mask = 0; mask<N; ++mask){
            int x = 0;
            for(int i = 0; i<n; ++i) if(mask & (1<<i)) {x|=nums[i];}
            if(x == y) ++ans;
        }
        return ans;
    }
};
