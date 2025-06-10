class Solution {
public:
    int maxDifference(string s) {
     vector<int> mp(26,0); int mx_odd = 0, mn_even = 105;
     for(char c : s) mp[c-'a']++;
     for(int i = 0; i<26; ++i){
        if(mp[i]){
            if(mp[i]&1) mx_odd = max(mx_odd  , mp[i]);
            else        mn_even = min(mn_even, mp[i]);
        }
     }
     return mx_odd - mn_even;
    }
};
