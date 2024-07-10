class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto s : logs){
            if(s[0] == '.' && s[1] == '/') continue;
            else if(s[0] == '.' && s[1] == '.') {ans--; ans = max(ans,0); }
            else ans++;
        }
        return max(ans,0);
    }
};
