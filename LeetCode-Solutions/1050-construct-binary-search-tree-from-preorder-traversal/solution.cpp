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

    void insert(TreeNode* &root, int &num){
        if(root == NULL) return;
        if(root->left == NULL && num < root->val){
            {TreeNode* l = new TreeNode(num); root->left = l;}
            return;
        }
        if(root->right == NULL && num > root->val){
            {TreeNode* r = new TreeNode(num); root->right = r;}
            return;
        }
        if(num < root->val) {insert(root->left,num);}
        else {insert( root->right,num);}
    }

    TreeNode* bstFromPreorder(vector<int>& A) {
        TreeNode* root = new TreeNode(A[0]);
        //insertion is log(n)
        for(int i = 1; i<A.size(); ++i){
            insert(root, A[i]);
        }
        return root;
    }
};
