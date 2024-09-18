auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    string largestNumber(vector<int>& A) {
        vector<string> v; for(int a : A) v.push_back(to_string(a));
        sort(v.begin(), v.end(), [](string &s1, string &s2){ return s1+s2 > s2+s1; });
        string ans = ""; for(string s : v) ans += s; 
        return ans[0] == '0'? "0" : ans;
    }
};
