class Solution {
public:

    void dfs(string s, int depth, unordered_set<string>& st, int &mx, unordered_map<string,int> &dp) {
        //idea: generate and go backwards
        
        //cache
        if(dp[s] >= depth) return; 
        dp[s] = depth; mx = max(mx,depth); 
        //transition
        for(int i = 0; i<s.size(); ++i){
            string tmp = s.substr(0, i) + s.substr(i+1);    
            if(st.find(tmp) != st.end()){dfs(tmp,depth+1,st,mx,dp);}
        }
    }

    int longestStrChain(vector<string>& A) {
        unordered_set<string> st(A.begin(), A.end()); unordered_map<string, int> dp;
        //idea generate all possible then dfs and keep max depth
        int mx = 1;
        for(string s : A){
            dfs(s, 1, st, mx,dp);
        }
        return mx;
    }
};
