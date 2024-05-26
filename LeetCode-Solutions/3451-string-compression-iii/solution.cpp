#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:

         struct t{int idx; char c;};
    string compressedString(string word) {
        vector<t> prefix;
        prefix.push_back({1,word[0]});
        char prev = word[0];
        int idx = 0;
        for(int i = 1; i<word.size(); ++i){
            if(word[i] == prev && prefix[idx].idx!=9){prefix[idx].idx++;}
            else{prefix.push_back({1,word[i]}); prev = word[i]; idx++;}
        }
        int n = prefix.size();
        char ans[2*n+1];
        ans[2*n] = '\0';
        int i = 0;
        for(auto it : prefix){
            char c = it.idx + '0';
            ans[i++] = c;
            ans[i++] = it.c;
        }
        string str(ans);
        return str;
    }
};
