#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size(), ans = 0;
        int mp[26] = {};
        for(char c : letters) 
            {mp[c - 'a']++;}
        for(int bitmask = 0; bitmask < (1<<n); ++bitmask){
            int tmp[26] = {};
            for(int j = 0; j<n; ++j){
                if(bitmask & (1<<j))
                    for(char c : words[j]) 
                        {tmp[c - 'a']++;}
            }
            int sc = 0;
            for(int i = 0; i<26; ++i){
                if(mp[i] < tmp[i]){sc = 0; break;}
                sc += score[i]*tmp[i];
            }
            if(sc) ans = max(ans,sc);
        }
        return ans;
    }
};
