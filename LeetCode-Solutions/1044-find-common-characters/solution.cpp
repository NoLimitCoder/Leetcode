const int INF = 2e9;
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> min_freq(26,INF);
        for(string word : words){
            vector<int> freq(26,0);
            for(char c : word){
                freq[c-'a']++;
            }
            for(int i = 0; i<26; ++i){
                min_freq[i] = min(min_freq[i], freq[i]);
            }
        }
        vector<string> ans;
        for(int i = 0; i<26; ++i){
            for(int j = 0; j<min_freq[i]; ++j){
                string tmp = "";
                tmp+= (char) 'a'+i;
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
