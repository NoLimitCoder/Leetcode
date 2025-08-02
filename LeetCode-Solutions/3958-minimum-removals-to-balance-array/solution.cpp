class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size(), j = 0, ans = n;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; ++i){
            if(j<i) j = i;
            while(j < n && nums[j] <= 1LL*nums[i]*k) ++j;
            ans = min(ans,n - (j-i));
        }
        return ans;
    }
};
