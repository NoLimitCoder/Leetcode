class Solution {
public:
    bool reportSpam(vector<string>& a, vector<string>& b) {
        int cnt = 0;
        set<string> st(b.begin(),b.end());
        for(string s : a){if(st.find(s) != st.end())cnt++;}
        return cnt >=2;
    }
};
