#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size(); vector<string> ord = {"electronics", "grocery", "pharmacy", "restaurant"};
        unordered_map<string,int> p;
        for(int i = 0; i<4;++i)p[ord[i]] = i;
        auto valid = [](const string& s){
            if(s.empty()) return 0;
            for(char c : s){ if(!isalnum(c) && c != '_') return 0; }
            return 1;
        };
        vector<tuple<int,string>> v;
        rep(i,n)
            {if(isActive[i] && p.count(businessLine[i]) && valid(code[i])) v.emplace_back(p[businessLine[i]], code[i]); }
        sort(v.begin(), v.end());
        vector<string> ans; for(auto &[a,s] : v) ans.push_back(s);
        return ans;
    }
};
