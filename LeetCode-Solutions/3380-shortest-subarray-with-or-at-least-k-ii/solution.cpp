auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

class Solution {
public:

    int minimumSubarrayLength(vector<int>& nums, int k) {
    int i = 0, j = 0, tmp = 0, n = nums.size(), mn = n+1;
    vector<int> idx(32,0);
    for(int j = 0; j<n; ++j){
        tmp |= nums[j];
        for(int x = 0; x<32; ++x) if(nums[j] & (1<<x)) idx[x]++;
        while(tmp >= k && i <= j){
            mn = min(mn,j-i+1);
            for(int x = 0; x<32; ++x)
                { if(nums[i] & (1<<x)){ idx[x]--; if(idx[x] == 0) tmp ^= (1<<x); } }
            ++i;
        }
    }
    return mn==n+1? -1 : mn;
    }
};
