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
    void DFS(TreeNode* root, vector<int> &ans, int depth){
        if(root == NULL) return;
        if(ans.size() == depth) ans.push_back(root->val);
        depth++;
        DFS(root->right,ans,depth);
        DFS(root->left,ans,depth);
    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        DFS(root,ans,0);
        return ans;

    }
};
