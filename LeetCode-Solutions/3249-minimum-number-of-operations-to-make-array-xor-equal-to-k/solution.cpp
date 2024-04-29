class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unsigned int ans = 0; for(int x : nums){ans ^= x;} ans ^= k; return __builtin_popcount(ans);
    }
};
