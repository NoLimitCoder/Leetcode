class Solution {
public:
    int countConsistentStrings(string A, vector<string>& W) {
        int ans = 0;
        set<char> st(A.begin(), A.end());
        for(string s : W){
            bool flag = 1;
            for(char c : s){
                if(st.find(c) == st.end()) flag = 0;
            }
            if (flag) ans++;
        }
        return ans;
    }
};
