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
    typedef long long ll;
    const ll INF = 4e18;
    bool isValidBST(TreeNode* root) {
        return ok(root, -INF, INF);
    }

    bool ok(TreeNode* root, ll mn, ll mx) {
        if(root == NULL) return 1;
        if(root->val <= mn || root->val >= mx) return 0;
        return ok(root->left, mn, root->val) && ok(root->right, root->val, mx);
    }

};
