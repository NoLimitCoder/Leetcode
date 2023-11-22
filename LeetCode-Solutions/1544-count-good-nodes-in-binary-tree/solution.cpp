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
    void DFS(TreeNode* root, int &val, int prevMax){
        if(root == nullptr) return;
        if(root->val >= prevMax) {val++; cout << root->val << ' ';}
        prevMax = max(prevMax, root->val);
        DFS(root->left, val, prevMax);
        DFS(root->right, val, prevMax);
    }

    int goodNodes(TreeNode* root) {
       if(root == nullptr){
           return 0;
       }
       int val = 0;
       DFS(root, val, root->val);
       return val;
    }
};
