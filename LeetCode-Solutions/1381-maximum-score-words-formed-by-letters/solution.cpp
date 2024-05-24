class Solution {
public:


    void wordCount(string str, unordered_map<char,int> &tmp){
        for(char c : str){tmp[c]++; }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int ans = 0;
        int n = words.size();
        unordered_map<char,int>mp;
        for(char c : letters){mp[c]++;}
        for(int bitmask = 0; bitmask < (1<<n); ++bitmask){
            unordered_map<char,int>tmp;
            for(int j = 0; j<n; ++j){
                if( bitmask & (1<<j)){
                    wordCount(words[j], tmp);
                }
            }
            bool flag = true;
            int sc = 0;
            for(auto it : tmp){
                if(mp[it.first] < it.second){flag = false; break;}
                sc += score[it.first - 'a']*it.second;
            }
            if(flag){
                //for(auto it : tmp){cout << it.first << ": " << it.second << ' ';}
                //cout << "score: " << sc << '\n';
                ans = max(ans,sc);
            }
        }
        return ans;
    }
};
