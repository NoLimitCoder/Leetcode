#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> mp(128,0);
        for(int i = 0; i<s.size(); ++i){
            mp[s[i]]++;
        }
        int ans = 0;
        bool flag = 0;
        for(auto it : mp){
            if(it % 2 == 0) ans += it;
            else{flag = 1; ans += it-1;}
        }
        return ans + flag;
    }
};
