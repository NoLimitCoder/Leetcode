class Solution {
public:
    
    
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double ans = 2e9;
        int i = 0, j = nums.size()-1;
        while(i<j){
            ans = min(ans, (nums[i]*1.0 + nums[j]*1.0)/2.0);
            
            i++; j--;
        }
        return ans;
    }
};
