#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        rep(i,k){
            int mn = INT_MAX;
            rep(i,nums.size()){
                mn = min(mn,nums[i]);
            }
            rep(i,nums.size()){
                if(nums[i] == mn){
                    nums[i] = nums[i]*m;
                    break;
                }
            }
        }
    return nums;
    }
};
