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
        sort(ans.begin(), ans.end());
        return ans;
    }

    void findSubsets(set<vector<int>> &st, vector<int>& nums, int mask, int idx){
        int n = nums.size();
        if(idx == n) return;
        //option1 not take element
        findSubsets(st,nums,mask,idx+1);
        //option2 take element
        mask |= (1<<idx);
        st.insert(maskSubset(nums,mask));
        findSubsets(st,nums,mask,idx+1);
    }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //approach: generate all subsets, then before adding to final answer check if final 
        //answer already has vector, if it does skip if not, add (or use set lol)
        set<vector<int>>st;
        vector<int> empty = {};
        st.insert(empty);
        findSubsets(st,nums,0,0);
        vector<vector<int>> ans;
        for(vector<int> it : st)
            {ans.push_back(it);}
        return ans;
    }
};
