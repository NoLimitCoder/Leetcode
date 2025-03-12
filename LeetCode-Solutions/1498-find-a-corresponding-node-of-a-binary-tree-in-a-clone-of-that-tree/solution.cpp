/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

TreeNode* ans;

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(cloned == NULL) return NULL;
        if(cloned->val == target->val) return cloned;
        auto l = getTargetCopy(original->left, cloned->left, target) ;
        auto r = getTargetCopy(original->right, cloned->right, target);
        return l == NULL ? r : l;
    }
};
