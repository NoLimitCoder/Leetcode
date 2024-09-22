typedef long long ll;
class Solution {
public:

    bool valid(vector<int> &mp1 ,vector<int> &mp2){
        for(int i = 0; i<26; ++i) if(mp1[i] < mp2[i]) return 0;
        return 1;
    }

    ll validSubstringCount(string w1, string w2) {
        vector<int> mp1(26), mp2(26);
        for(int i = 0; i<w2.size(); ++i){ mp2[w2[i]-'a']++; }
        ll ans = 0, i = 0, j = 0, n = w1.size();
        for(int j = 0; j<n; ++j){
            mp1[w1[j]-'a']++;
            while(valid(mp1,mp2))
                { ans += (n-j); mp1[w1[i]-'a']--; ++i; }
        }
        return ans;
    }
};

