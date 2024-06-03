#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    int characterReplacement(string s, int k) {
        int mp[26] = {0};
        auto _max = [](int mp[]) {int x = 0; for(int i=0;i<26;++i){x = max(x, mp[i]);} return x;};
        int i = 0, j = 0, ans = 0;
        while(j<s.size()){
            mp[s[j]-'A']++;
            if( (j-i+1) - _max(mp) > k) {mp[s[i]-'A']--; i++;}
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
