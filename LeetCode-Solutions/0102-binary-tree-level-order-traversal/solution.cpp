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

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int s = q.size();
            for(int i = 0; i<s; ++i){
                TreeNode* top = q.front(); q.pop();
                if(top == NULL) continue;
                q.push(top->left);
                q.push(top->right);
                tmp.push_back(top->val);
            }
            if(tmp.size() != 0) ans.push_back(tmp);
        }
        return ans;
    }

};
