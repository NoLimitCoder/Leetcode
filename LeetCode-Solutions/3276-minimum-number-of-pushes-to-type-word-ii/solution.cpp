auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26);
        for(char c : word){ mp[c-'a']++; }
        sort(mp.rbegin(), mp.rend());
        int ans = 0;
        for(int i = 0; i<26; ++i){
            ans += (i/8+1) * mp[i];
        }
        return ans;
    }
};
