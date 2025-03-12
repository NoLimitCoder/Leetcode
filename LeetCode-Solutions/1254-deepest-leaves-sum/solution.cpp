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


    void dfs(TreeNode* root, int &sum, int depth, int &mx_depth) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL && depth == mx_depth) sum += root->val;
        if(mx_depth < depth) {sum = root->val; mx_depth = depth;}
        //if(mx_depth == depth) {sum += root->val;}
        dfs(root->left, sum, depth+1, mx_depth); dfs(root->right, sum, depth+1, mx_depth);
    }

    int deepestLeavesSum(TreeNode* root) {
        int sum = 0, mx_depth = 0; 
        dfs(root,sum,0,mx_depth);
        //flag = 1;
        //dfs(root,sum,0,flag,mx_depth);
        return sum;
    }
};
