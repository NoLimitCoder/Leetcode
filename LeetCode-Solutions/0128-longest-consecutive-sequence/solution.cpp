class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        if(nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); ++i){
            cout << nums[i] << ' ';
        }cout << '\n';
        int ans = 1;
        int mx = 1;
        for(int i = 0; i<nums.size()-1; ++i){
            if(nums[i+1] - nums[i] == 0){continue;}
            if(abs(nums[i+1] - nums[i]) == 1){
                ans++;
            }
            else{
                ans = 1;
            }
            mx = max(mx,ans);
        }
        return mx;
    }
};
