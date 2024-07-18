#pragma GCC optimize("Ofast") #pragma GCC target("avx2") auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
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

    void dfs(TreeNode* &root, string &tmp, vector<string> &ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {ans.push_back(tmp); return;}
        tmp += "L"; dfs(root->left,  tmp, ans); tmp.pop_back();
        tmp += "R"; dfs(root->right, tmp, ans); tmp.pop_back();
    }

    int countPairs(TreeNode* &root, int distance) {
        int ans = 0; string tmp; vector<string> paths; 
        dfs(root, tmp="", paths); 
        for(int i = 0; i<paths.size(); ++i){
            for(int j = i+1; j<paths.size(); ++j){
                int x = 0; for(; x<paths[i].size(); ++x){ if(paths[i][x] != paths[j][x]) break; }
                int dist = paths[i].size() + paths[j].size() - 2*x;
                if(dist <= distance) ++ans;
            }
        }
        return ans;
    }
};
