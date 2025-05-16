class Solution {
public:
    vector<string> ans;
    void dfs(string &s, string tmp, int i){
        if(i == s.size()){ans.push_back(tmp); return;}
        if(isalpha(s[i])){
            dfs(s,tmp + string(1,tolower(s[i])), i+1);
            dfs(s,tmp + string(1,toupper(s[i])), i+1);
        }
        else{dfs(s, tmp + s[i], i+1);}
    }
    vector<string> letterCasePermutation(string s) {
        ans.resize(0);
        dfs(s,"",0);
        return ans;
    }
};
