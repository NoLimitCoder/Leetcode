auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */class Solution {
private:

    void dfs(TreeNode* &root, unordered_set<int>&st, vector<TreeNode*>& res){
        if (root == nullptr) return;
        dfs(root->left,  st, res); dfs(root->right, st, res);
        if (st.find(root->val) != st.end()){
            if(root->left  != NULL) res.push_back(root->left);
            if(root->right != NULL) res.push_back(root->right);
            root = NULL;
        }
    }


public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& d) {
        vector<TreeNode*> res;
        unordered_set<int>st(d.begin(), d.end());
        dfs(root, st, res);
        if(root != NULL) res.push_back(root);
        return res;
    }
};
