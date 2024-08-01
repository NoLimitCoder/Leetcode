auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(string s : details)
            if( stoi(s.substr(11,2)) > 60 ) ++ans;
        return ans;
    }
};
