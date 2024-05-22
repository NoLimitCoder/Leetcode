class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPalindrome(string s){
        for(int i = 0; i<s.size(); ++i){
            if(s[i] != s[s.size()-i-1])
                return false;
        }
        return true;
    }
        void dfs(vector<string> V, int idx, string &s){
        if (idx == s.size()) {ans.push_back(V); return;}
        for (int i = idx; i < s.size(); ++i) {
            string cur = s.substr(idx, i - idx + 1);
            if (isPalindrome(cur)) {
                V.push_back(cur);
                dfs(V, i + 1, s);
                V.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        ans.clear();
        vector<string> V;
        dfs(V, 0, s);
        return ans;
    }
};
