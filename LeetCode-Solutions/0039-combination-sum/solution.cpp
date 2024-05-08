class Solution {
public:
    
    void dfs(int &target, int sum, int idx, vector<int> cur, vector<int>& candidates, vector<vector<int>>& ans){
        //base cases
        if (sum == target) {ans.push_back(cur); return;}
        if (sum > target || idx == candidates.size()) return;
        //either take or not take (in order)
        //option 1 take the cur element
        sum += candidates[idx]; //add element to sum
        cur.push_back(candidates[idx]); //push_back element
        dfs(target, sum, idx, cur, candidates, ans);
        //option 2 don't take the cur element
        sum -= candidates[idx]; //remove the element that we have already summed
        cur.pop_back(); //remove the element that we have already pushed_back
        dfs(target, sum, idx+1, cur, candidates, ans);

    }
    

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans = {};
        vector<int> cur = {};
        dfs(target, 0, 0, cur, candidates, ans);
        return ans;
    }
};
