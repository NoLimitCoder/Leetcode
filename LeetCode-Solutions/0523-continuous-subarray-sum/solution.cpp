#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>st;
        int sum = nums[0]%k;
        for(int i = 1; i<nums.size(); ++i){
            sum += nums[i];
            if(sum%k == 0 || st.find(sum%k) != st.end()) return true;
            st.insert(sum-nums[i]);
            sum %= k;
        }
        return false;
    }
};
