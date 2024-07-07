auto init = [](){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
const int INF = 2e9;
class Solution {
public:

struct vertex{
    char l; int cost; vector<vertex*> child; 
    vertex(char c): l(c), cost(INF) {child.assign(26,NULL);}
};

struct Trie{
    vertex* root;
    Trie(){root = new vertex(' ');}
    
    void insert(string word, int cost){
        vertex* cur = root;
        for(char c : word){
            if(cur->child[c-'a'] == NULL)
                cur->child[c-'a'] = new vertex(c);
            cur = cur->child[c-'a'];
        }
        cur->cost = min(cur->cost, cost);
    }

};

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        Trie trie; int n = target.size(); vector<int> dp(n+1,INF);
        for(int i = 0; i < words.size(); ++i){ trie.insert(words[i], costs[i]); }
        //base case -> it costs us 0 to make a string starting at 0
        dp[0] = 0;
        //starting at each index of the string
        for(int i = 0; i<n; ++i){
            //if this index is not reachable continue
            if(dp[i] == INF) continue;
            //Trie for early stopping
            vertex* cur = trie.root;
            //starting at the curret latest valid index
            for(int j = i; j<n; ++j){
                //if this isn't reachable, early stopping
                if(cur->child[target[j] - 'a'] == NULL) break;
                cur = cur->child[target[j]-'a'];
                //if this is the ending of a word, push to dp of next cell to indicate we can form a new word starting at that index for a cost of cur->cost
                if(cur->cost != INF){
                    //the cost will be the cost of being in this subsequence which starts at i (dp[i]) + the current cost
                    dp[j+1] = min(dp[j+1], dp[i] + cur->cost);
                }
            }
        }
        return dp[n] == INF? -1 : dp[n];
    }
};
