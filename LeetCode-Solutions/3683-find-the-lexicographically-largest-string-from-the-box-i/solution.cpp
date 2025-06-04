auto init = []() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
class Solution {
public:
    string answerString(string s, int x) {
        if(x == 1) return s;
        int n = s.size(), len = n-x+1; char c = *max_element(s.begin(), s.end()); 
        string ans = "";
        for(int i = 0; i<n; ++i) if(s[i] == c) { ans = max(ans,s.substr(i, min(n-i,len))); }
        return ans;
    }
};
