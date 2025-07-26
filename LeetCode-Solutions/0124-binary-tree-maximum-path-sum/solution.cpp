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
 */
class Solution {
public:

    int dfs(TreeNode* root, int &mx) {
        if(root == NULL) return 0;
        int l = dfs(root->left,mx), m = root->val, r = dfs(root->right,mx);
        int cur = max({l+m, m, m+r});
        mx = max({mx,cur, l+m+r});
        return cur;
    }

    int maxPathSum(TreeNode* root) {
        int mx = -2e9;
        dfs(root, mx);
        return mx;
    }
};
