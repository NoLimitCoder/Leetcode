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
//const int INF = 2e9;
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool isValidBST(TreeNode* root, long long mn, long long mx) {
        if(root==nullptr)return true;
        if((root->val >= mx || root->val <= mn)) return false;
        return isValidBST(root->left,mn,root->val) && isValidBST(root->right,root->val,mx);
    }

};
