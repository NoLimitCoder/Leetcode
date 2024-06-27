class WordDictionary {
    struct vertex{
        char l; bool end; vector<vertex*>child;
        vertex(char c): l(c), end(0) {child.assign(26,NULL);}
    };
public:
    vertex* root;
    WordDictionary() {
        root = new vertex(' ');
    }
    
    void addWord(string word) {
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
        return search(cur, word, 0);
    }

    bool search(vertex* root, string &word, int i) {
        if(i == word.size()) return root->end;
        char c = word[i];
        if(c == '.'){
            for(vertex* chld : root->child){
                if( chld!=NULL && search(chld,word,i+1)) return true;
            }
            return false;
        }
        else{
            if(root->child[c-'a'] == NULL)
                return false;
            return search(root->child[c-'a'], word, i+1);
        }

    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
