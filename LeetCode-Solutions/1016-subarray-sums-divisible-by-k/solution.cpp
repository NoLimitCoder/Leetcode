#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:

    int mod(int a, int &k){
        return ((a%k)+k)%k;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int mp[10005] = {}; mp[0]++;
        int ans = 0, sum = 0;
        for(int i = 0; i<nums.size(); ++i){
            sum = mod(sum+mod(nums[i],k),k);
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;

    }
};
