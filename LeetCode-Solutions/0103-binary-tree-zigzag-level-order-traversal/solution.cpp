class Solution {
public:
    void dfs(TreeNode* u, int l, vector<vector<int>>& ans){
        if(u == NULL) return;
        if(ans.size() == l){ ans.push_back(vector<int>()); }
        if(!(l&1)){ ans[l].push_back(u->val);}
        else      { ans[l].insert(ans[l].begin(), u->val);}
        dfs(u->left, l+1, ans); dfs(u->right, l+1, ans);
    };
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
