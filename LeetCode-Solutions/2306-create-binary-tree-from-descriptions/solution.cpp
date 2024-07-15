auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
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

TreeNode* build(TreeNode* root, unordered_map<int,pair<int,int>> &mp){
    if(root == NULL) return NULL;
    root->left  = (mp[root->val].first )? new TreeNode(mp[root->val].first ) : NULL;
    root->right = (mp[root->val].second)? new TreeNode(mp[root->val].second) : NULL;
    build(root->left,mp); build(root->right,mp);
    return root;
}

    TreeNode* createBinaryTree(vector<vector<int>>& D) {
        unordered_map<int,pair<int,int>>mp; unordered_map<int,int>P;
        for(int i = 0; i<D.size(); ++i){
            int p = D[i][0], c =D[i][1], d = D[i][2];
            if(d) mp[p].first = c;
            else  mp[p].second = c;
            P[c] = p;
        }
        int src = -1;
        for(int i = 0; i<D.size(); ++i){ if(P.find(D[i][0]) == P.end()) {src = D[i][0]; break;} }
        TreeNode *root = new TreeNode(src);
        build(root, mp);
        return root;
    }
};
