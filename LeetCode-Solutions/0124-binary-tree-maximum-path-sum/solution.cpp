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
#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    int dfs(TreeNode* root, int &mx){
        if(root == NULL) return 0;
        int left = dfs(root->left,mx), right = dfs(root->right,mx);
        int tmp = max({left + root->val, right + root->val, root->val});
        mx = max({mx, tmp, left + right + root->val});
        return tmp;
    }

    int maxPathSum(TreeNode* root) {
        int mx = -2e9;
        dfs(root, mx);
        return mx;
    }
};
