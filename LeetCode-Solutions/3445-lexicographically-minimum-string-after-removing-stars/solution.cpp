auto init = []() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
class Solution {
public:
    string clearStars(string s) {
        int n = s.size(); vector<vector<int>> mp(26); vector<bool> vis(n, 1);
        for(int i = 0; i<n; ++i){
            if(s[i] == '*'){
                vis[i] = 0;
                for(int j = 0; j<26; ++j){
                    if(!mp[j].empty()){
                        vis[mp[j].back()] = 0; mp[j].pop_back();
                        break;
                    }
                }
            }
            else{
                mp[s[i]-'a'].push_back(i);
            }
        }
        string ans = "";
        for(int i = 0; i<n; ++i){ 
            if(vis[i]) ans += s[i]; 
        }
        return ans;
    }
};
