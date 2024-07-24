auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:
    int countSubstrings(string s) {
      int n = s.size(), ans = 0, i, j;
      for(int idx = 0; idx<n; ++idx){
        i = idx, j = idx;
        while(i>=0 && j<n){ if(s[i] == s[j]) {ans++; --i; ++j;} else break; }
        i = idx-1, j = idx;
        while(i>=0 && j<n){ if(s[i] == s[j]) {ans++; --i; ++j;} else break; }
      }
      return ans;
    }
};
