#pragma GCC optimize("O3,unroll-loops")

class Solution {
public:
    struct vertex{
        bool bit; vector<vertex*>child;
        vertex(bool b): bit(b) {child.assign(2,NULL);}
    };
struct Trie{

    vertex *root;
    Trie(){root = new vertex(0);}

    void insert(int &x){
        //cout << bset.to_ulong() << "->";
        vertex* cur = root;
        for(int i = 30; i>=0; --i){
            bool bit = x&(1<<i);
            if(cur->child[ bit ] == NULL)
                cur->child[ bit ] = new vertex(bit);
            cur = cur->child[ bit ];
           // cout <<bset[i] << ' ';
        }//cout << '\n';
    }
    int search(int &x){
        //cout << bset.to_ulong() << "->";
        int ans = 0;
        vertex* cur = root;
        for(int i = 30; i>=0; --i){
            bool bit = x&(1<<i);
            if(cur->child[ bit ^ 1] == NULL){
                ans |= (bit<<i);
                cur = cur->child[bit];
            }
            else{
                ans |= ((bit^1)<<i);
                cur = cur->child[bit ^ 1];
            }
            //cout <<ans[i] << ' ';
        } //cout << '\n';
        return x ^ ans;
    }
};



    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &i : nums){
            trie.insert(i);
        }
        //cout << '\n';
        int mx = 0;
        for(auto &i : nums){
            mx = max(mx, trie.search(i));
        }
        return mx;
    }
};
