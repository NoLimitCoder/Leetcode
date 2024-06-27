class Trie {
    struct vertex{
        char l; bool end; vector<vertex*>child;
        vertex(char c): l(c), end(0) {child.assign(26,NULL);}
    };
public:
    vertex* root;
    Trie(){root = new vertex(' ');}

    void insert(string word) {
        vertex* cur = root;
        for(char c : word){
            if(cur->child[c-'a'] == NULL)
                cur->child[c-'a'] = new vertex(c);
            cur = cur->child[c-'a'];
        }
        cur->end = 1;
    }
    
    bool search(string word) {
        vertex* cur = root;
        for(char c : word){
            if(cur->child[c-'a'] == NULL)
                return 0;
            cur = cur->child[c-'a'];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        vertex* cur = root;
        for(char c : prefix){
            if(cur->child[c-'a'] == NULL)
                return 0;
            cur = cur->child[c-'a'];
        }
        return 1; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
