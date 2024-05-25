#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:

bool check(vector<string> &words, unordered_set<string> &st){
    bool flag = true;
    for(string w : words){
        if(st.find(w) == st.end()){flag = false; break;}
    }
    return flag;
}

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<string> V;
        for(int bitmask = 0; bitmask < (1<<n-1); ++bitmask){
            vector<string> words;
            int prev_idx = 0;
            for(int j = 0; j<n; ++j){
                if(bitmask & (1<<j)){
                    string tmp = s.substr(prev_idx,j-prev_idx+1);
                    prev_idx = j+1;
                    words.push_back(tmp);
                } 
            }
            words.push_back(s.substr(prev_idx,n));
            if(check(words,st)){
                string ans = "";
                for(int i = 0; i< words.size(); ++i){
                    ans+=words[i];
                    if(i != words.size()-1) ans+=" ";
                }
                V.push_back(ans);
            }
        }
        return V;
    }
};

//+  catsanddog
//0 [1 2 3 4 5 6 7 8 9 10]
//dp[0]  = base case
//dp[3]  = {0}
//dp[4]  = {0}
//dp[7]  = {4, 3}
//dp[10] = {7}
//


