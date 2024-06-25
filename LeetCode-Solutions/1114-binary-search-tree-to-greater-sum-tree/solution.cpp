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
//in order traversal starting from the right
    TreeNode* bstToGst(TreeNode* root) {
        int extra = 0;
        dfs(root,extra);
        return root;
    }

    void dfs(TreeNode* root, int &extra) {
        if(root == NULL) return;
        dfs(root->right,extra);
        extra = root->val = extra + root->val;
        dfs(root->left,extra);
        
    }
};
