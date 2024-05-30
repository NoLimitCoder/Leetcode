/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#pragma GCC optimize("O3,unroll-loops")

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        //bfs
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front(); q.pop();
            if(cur == NULL) {ans += "N,"; continue;}
            else {ans += to_string(cur->val);}
            ans+=",";
            q.push(cur->left); q.push(cur->right);
        }
        ans.pop_back(); //removing the last ','
        return ans;
    }

vector<string> tokenize(string str, char delimiter){
    vector<string> token_v;
    size_t start = str.find_first_not_of(delimiter), end=start;
    while (start != string::npos){
        end = str.find(delimiter, start);
        token_v.push_back(str.substr(start, end-start));
        start = str.find_first_not_of(delimiter, end);
    }
    return token_v;
}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data_str) {
        if(data_str[0] == 'N') return NULL;
        vector<string> data = tokenize(data_str,',');
        int n = data.size();
        //bfs
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(stoi(data[0]));
        q.push(root);
        int idx = 1;
        while(!q.empty()){
            TreeNode* cur = q.front(); q.pop();
            if(cur == NULL) continue;
            if( (idx   < n) && (data[idx  ] != "N") ) {cur->left  = new TreeNode(stoi(data[idx  ]));}
            if( (idx+1 < n) && (data[idx+1] != "N") ) {cur->right = new TreeNode(stoi(data[idx+1]));}
            q.push(cur->left); q.push(cur->right);
            idx+=2;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
