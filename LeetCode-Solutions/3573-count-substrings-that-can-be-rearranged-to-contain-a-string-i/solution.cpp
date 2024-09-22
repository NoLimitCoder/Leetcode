typedef long long ll;
class Solution {
public:

    bool valid(map<char,int>&mp1 ,map<char,int> &mp2){
        for(auto it : mp2){
            if(mp1[it.first] >= it.second);
            else return false;
        }
        return 1;
    }

    long long validSubstringCount(string w1, string w2) {
        map<char,int>mp1, mp2;
        for(int i = 0; i<w2.size(); ++i){mp2[w2[i]]++; }
        ll ans = 0;
        int i = 0, j = 0;
        int n = w1.size();
        while(j < n){
            mp1[w1[j]]++; 
            while(valid(mp1,mp2)) {
                //cout << i << ' ' <<j << '\n';
                ans += (n-j);
                mp1[w1[i]]--; ++i;
            }
            ++j;
        }
        return ans;
    }   
};

