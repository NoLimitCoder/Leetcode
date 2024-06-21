class Solution {
public:
struct vertex{
  char l; bool end; vector<vertex*>child;
  vertex(char c): l(c), end(0) {child.assign(26,NULL);}
};

struct Trie{
    vertex* root;
    Trie(){root = new vertex('l');}

    void insert(string word){
      vertex* cur = root;
      for(char c : word){
        if(cur->child[c-'a'] == NULL)
          cur->child[c-'a'] = new vertex(c);
        cur = cur->child[c-'a'];
      }
      cur->end = 1;
    }

    bool search(string word){
      vertex* cur = root;
      for(char c : word){
        if(cur->child[c-'a'] == NULL)
          return false;
        cur = cur->child[c-'a'];
      }
      return cur->end;
    }

    bool startsWith(string word){
      vertex* cur = root;
      for(char c : word){
        if(cur->child[c-'a'] == NULL)
          return false;
        cur = cur->child[c-'a'];
      }
      return 1;
    }

    bool allExist(string word){
      vertex* cur = root;
      for(char c : word){
        if(cur->child[c-'a'] == NULL || !cur->child[c-'a']->end)
          return false;
        cur = cur->child[c-'a'];
      }
      return 1;
    }
};

    string longestWord(vector<string>& words) {
        int len = 0; string ans;
        Trie *trie = new Trie(); for(string word: words){trie->insert(word);}
        for(string word : words){
            if(trie->allExist(word)){
                if(word.size() > len){ans = word; len = word.size();}
                else if(word.size() == len && word < ans){ans = word;}
            }
        }
        return ans;
    }
};
