#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i = 0, j = 0, ans = 0, n = s.size();
        for(int i = 0; i<n; ++i){
            if(mp.find(s[i]) != mp.end()) j = max(j, mp[s[i]]+1);
            ans = max(ans,i-j+1);
            mp[s[i]] = i;
        }
        return ans;
    }
};
