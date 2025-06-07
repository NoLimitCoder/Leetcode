auto init = []() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '
class Solution {
public:

    char nextMinChar(vector<int> &mp){ 
        for(int i = 0; i<26; ++i) {if(mp[i]) return char('a' + i);} return 0; 
    }

    string robotWithString(string s) {
        int n = s.size(); vector<int> mp(26); string ans = ""; stack<int> stk;
        for(int i = 0; i<n; ++i){ mp[s[i]-'a']++; }
        
        for (char c : s) {
            stk.push(c); mp[c-'a']--;
            while (!stk.empty() && stk.top() <= nextMinChar(mp)){
                ans += string(1,stk.top()); stk.pop();
            }
        }
        while(!stk.empty()) {ans += string(1,stk.top()); stk.pop();}
        return ans;
    }
};
