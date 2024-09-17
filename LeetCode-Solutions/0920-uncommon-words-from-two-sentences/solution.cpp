class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> mp; vector<string> ans;
        string tmp = "";
        for(char c : s1){
            if(c == ' ') {cout << tmp << '\n'; mp[tmp]++; tmp = "";}
            else tmp += c;
        }
        if(tmp != "") mp[tmp]++;
        tmp = "";
        for(char c : s2){
            if(c == ' ') {cout << tmp << '\n'; mp[tmp]++; tmp = "";}
            else tmp += c;
        }
        if(tmp != "") mp[tmp]++;
        tmp = "";
        for (auto it : mp){
            if(it.second == 1){ans.push_back(it.first);}
        }
        return ans;
    }
};
