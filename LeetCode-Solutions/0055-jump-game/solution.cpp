class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = nums[0];
        for(int i = 0; i<nums.size(); ++i){
            if(i > mx) return false;
            mx = max(mx, i+nums[i]);
        }
        return true;
    }
};
