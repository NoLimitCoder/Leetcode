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

    void dfs(TreeNode* root, vector<int>&A){
        if(root == NULL) return;
        dfs(root->left,A); A.push_back(root->val); dfs(root->right,A);
    }

    TreeNode* buildBbst(int l, int r, vector<int>&A){
        if(l>r) return NULL;
        int m = (l+r)/2;
        TreeNode* root = new TreeNode(A[m]);
        root->left = buildBbst(l,m-1,A);
        root->right = buildBbst(m+1,r,A);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> A;
        dfs(root,A);
        return buildBbst(0,(int)A.size()-1,A);
    }
};
