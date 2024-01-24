#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        ios();
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
    }
};
