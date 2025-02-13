#pragma GCC optimize(O3,"unroll-loops")
auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size(); vector<int> LPS(n,0);
        //kmp
        for(int i = 1, j = 0; i<n;){ s[i]==s[j]? LPS[i++] = ++j : j? j = LPS[j-1] : ++i; }
        //idea for kmp: //are chars equal? yes -> increase lps : no -> at least is l > 0? yes -> go to LPS[l-1] no -> just increase i bro
        return s.substr(0,LPS.back());
    }
};
