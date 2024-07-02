#pragma GCC optimize("O3,unroll-loops")

class Solution {
public:

struct Trie{

    struct vertex{
        char l; bool end; int count; vector<vertex*>child;
        vertex(char c): l(c), end(0), count(0) {child.assign(26,NULL);}
    };

    vertex* root;

    Trie(){root = new vertex(' ');}

    void insert(string word){
        vertex* cur = root;
        for(char c : word){
            if(cur->child[c-'a'] == NULL)
                cur->child[c-'a'] = new vertex(c);
            cur->child[c-'a']->count++;
            cur = cur->child[c-'a'];
        }
        cur->end = 1;
    }

    string lcp(string word, int n){
        vertex* cur = root;
        string ans = "";
        for(char c : word){
            if(cur->child[c-'a'] == NULL || cur->child[c-'a']->count != n)
                return ans;
            ans += string(1,c);
            cur = cur->child[c-'a'];
        }
        return ans;
    }

};

    string longestCommonPrefix(vector<string>& strs) {
        Trie trie; 
        for(string s : strs) trie.insert(s);
        return trie.lcp(strs[0], strs.size());
    }
};
