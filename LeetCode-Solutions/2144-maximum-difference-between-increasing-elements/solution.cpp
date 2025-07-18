class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mx = -1, n = nums.size();
        for(int i = 0; i<n; ++i){
            for(int j = i+1; j<n; ++j){
                if(nums[i] < nums[j]){mx = max(mx, nums[j]-nums[i]);}
            }
        }
        return mx;
    }
};
