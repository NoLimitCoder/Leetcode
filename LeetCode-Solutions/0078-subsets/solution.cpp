class Solution {
public:

    vector<int> maskSubset(vector<int>& nums, int mask){
        int n = nums.size();
        vector<int> ans(0);
        for(int i = 0; i<n; ++i){
            if(mask & (1<<i)){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }

    void findSubsets(vector<vector<int>> &ans, vector<int>& nums, int mask, int idx){
        int n = nums.size();
        if(idx == n) return;
        //option1 not take element
        findSubsets(ans,nums,mask,idx+1);
        //option2 take element
        mask |= (1<<idx);
        ans.push_back(maskSubset(nums,mask));
        findSubsets(ans,nums,mask,idx+1);
    }



    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        findSubsets(ans,nums,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
