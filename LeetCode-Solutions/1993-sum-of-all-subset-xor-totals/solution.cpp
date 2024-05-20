class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), mask = (1<<n), ans = 0;
        for(int bitmask = 0; bitmask < mask; ++bitmask){
            int tmp = 0;
            for(int i = 0; i<n; ++i){
                if(bitmask & (1<<i)){
                    tmp ^= (nums[i]);
                }
            }
            ans += tmp;
        }
        return ans;
    }
};
