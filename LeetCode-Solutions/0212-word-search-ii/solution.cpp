#pragma GCC optimize("O3,unroll-loops")
//approach 2: dfs + trie (not building the vector space)
class Solution {
public:

struct vertex{
    char l; bool end; vector<vertex*>child;
    vertex(char c): l(c), end(0) {child.assign(26,NULL);}
};

struct Trie{

    vertex* root;
    Trie(){root = new vertex(' ');}

    void insert(string word){
        vertex* cur = root;
        for(char c : word){
            if(cur->child[c-'a'] == NULL)
                cur->child[c-'a'] = new vertex(c);
            cur = cur->child[c-'a'];
        }
        cur->end = 1;
    }

    bool startsWith(string word){
        vertex* cur = root;
        for(char c : word){
            if(cur->child[c-'a'] == NULL)
                return 0;
            cur = cur->child[c-'a'];
        }
        return 1;
    }

    bool search(string word){
        vertex* cur = root;
        for(char c : word){
            if(cur->child[c-'a'] == NULL)
                return 0;
            cur = cur->child[c-'a'];
        }
        return cur->end;
    }

};

    int dx[4]={1, -1, 0,  0};
    int dy[4]={0,  0, 1, -1};
    struct P {int x, y;};
    void dfs(P pos, vector<vector<char>>& board, vertex* root, unordered_set<string> &ans, string cur){
        if(pos.x < 0 || pos.x >= board.size() || pos.y < 0 || pos.y >= board[0].size() || board[pos.x][pos.y] == '#' 
        || root->child[board[pos.x][pos.y]-'a'] == NULL ) return;
        char tmp = board[pos.x][pos.y];
        cur+=tmp;
        root = root->child[board[pos.x][pos.y]-'a'];
        if(root->end) {ans.insert(cur);}
        board[pos.x][pos.y] = '#';
        for(int k = 0; k<4; ++k){dfs({pos.x+dx[k], pos.y+dy[k]}, board, root, ans, cur);}
        board[pos.x][pos.y] = tmp;
        cur.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> st; Trie trie;
        for(auto s : words) trie.insert(s);
        int m = board.size(); int n = board[0].size();
        for(int i = 0; i<m; ++i)
            for(int j = 0; j<n; ++j)
                dfs({i,j},board,trie.root,st, "");
        vector<string> ans; for(auto it : st) ans.push_back(it);
        return ans;
    }
};
