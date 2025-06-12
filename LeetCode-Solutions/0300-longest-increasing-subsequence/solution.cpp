class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int i : nums){
            int pos = (lower_bound(dp.begin(), dp.end(), i) - dp.begin());
            if(pos == dp.size()) dp.push_back(i);
            else dp[pos] = i;
        }
        return dp.size();
    }
};
