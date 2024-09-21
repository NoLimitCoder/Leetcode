class Solution {
public:

struct Trie{
    struct vertex{
        int val; bool end; vector<vertex*>child;
        vertex(int x): val(x), end(0) {child.assign(10,NULL);}
    };
    vertex* root;
    Trie(){root = new vertex(0);}
    void insert(int x){
        vertex* cur = root;
        string s = to_string(x);
        for(char c : s){
            int i = c-'0';
            if(cur->child[i] == NULL)
                cur->child[i] = new vertex(i);
            cur = cur->child[i];
        }
        cur->end = 1;
    }
    void dfs(vertex* cur, vector<int> & ans, int x){
        if(cur == NULL) return;
        if(cur->end) ans.push_back(x);
        for(int i = 0; i<=9; ++i){
            dfs(cur->child[i], ans, x*10+i);
        }
    }
};

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        Trie trie;
        for(int i = 1; i<=n; ++i) trie.insert(i);
        trie.dfs(trie.root,ans,0);
        return ans;
        
    }
};
