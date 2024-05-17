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

    void dfs(TreeNode* &root, int target){
        if(root == NULL) return;
        dfs(root->left, target);
        dfs(root->right, target);
        //cout << root->val << ' ';
        if(root->left == NULL && root->right == NULL && root->val == target) root = NULL;
    }


    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root, target);
        return root;
    }
};
