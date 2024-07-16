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
    void dfs(TreeNode* root, string &start, int &s, string &tmp){
        if(root == NULL) return;
        if(root->val == s) {start = tmp; return;}
        tmp += "L"; dfs(root->left,  start, s, tmp); tmp.pop_back();
        tmp += "R"; dfs(root->right, start, s, tmp); tmp.pop_back();
    }

    string getDirections(TreeNode* root, int s, int d) {
        string start, end, tmp, ans = "";
        dfs(root, start, s, tmp=""); dfs(root, end, d, tmp="");
        int i = 0; for(; i<start.size(); ++i){ if(start[i] != end[i]) break; }
        for(int j = 0; j<start.size()-i; ++j) ans+="U";
        for(int j = i; j<end.size()    ; ++j) ans+=end[j];
        return ans;
    }
};
