#define deb(x)  cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '
class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> ans;
        string tmp = "";
        unordered_set<string> st;
        for(int i = 0; i<s.size(); ++i){
            tmp += s[i];
            //deb(tmp);
            if(st.find(tmp) == st.end()){
                ans.push_back(tmp);
                st.insert(tmp);
                tmp = "";
            }
        }
        if(tmp != "" && st.find(tmp) == st.end()) ans.push_back(tmp);
        return ans;
    }
};
