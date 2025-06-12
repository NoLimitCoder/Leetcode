class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int mx = 0;
        for(int i = 0; i<nums.size()-1; ++i){
            mx = max(mx,abs(nums[i] - nums[i+1]));
        }
        return max(mx, abs(nums[0] - nums[nums.size()-1]));
    }
};
