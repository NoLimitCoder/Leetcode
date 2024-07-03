#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       vector<int>mp[26];
       for(int i = 0; i<s.size(); ++i)
           {mp[s[i] -'a'].push_back(i);}
       int count = 0;
       for(string word : words){
            int pos = -1; bool flag = true;
            for(char c : word){
                auto it = upper_bound(mp[c-'a'].begin(), mp[c-'a'].end(), pos);
                if(it == mp[c-'a'].end()) {flag = false; break;}
                pos = *it;
            }
            if(flag) count++;
        }
        return count;
    }
};
