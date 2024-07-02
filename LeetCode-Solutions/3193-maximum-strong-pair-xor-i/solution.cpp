#pragma GCC optimize("O3,unroll-loops")

class Solution {
public:
    struct Trie{
        struct vertex{
            bool bit; vector<vertex*>child;
            vertex(bool b): bit(b) {child.assign(2,NULL);}
        };

        vertex *root;
        Trie(){root = new vertex(0);}

        void insert(int &x){
            vertex* cur = root;
            for(int i = 30; i>=0; --i){
                bool bit = x&(1<<i);
                if(cur->child[ bit ] == NULL)
                    cur->child[ bit ] = new vertex(bit);
                cur = cur->child[ bit ];
            }
        }
        int search(int &x){
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
            }
            return x ^ ans;
        }

        bool isEmpty(vertex* root){
            if(root == NULL) return true;
            for (int i = 0; i <= 1; i++)
                if (root->child[i]) return false;
            return true;
        }

        void remove(vertex* root, int x, int i=30){
            if(root == NULL || i < 0) return;
            bool bit = x&(1<<i);
            remove(root->child[bit], x, i-1);
            if(isEmpty(root->child[bit])){
                delete(root->child[bit]);
                root->child[bit] = NULL;
            }
        }

    };
    int maximumStrongPairXor(vector<int>& nums) {
        Trie trie;
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, ans = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            trie.insert(nums[i]);
            while (nums[j] * 2 < nums[i])
                trie.remove(trie.root,nums[j++]);
            ans = max(ans, trie.search(nums[i]));
        }
        return ans;
    }
};
