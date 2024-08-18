class Solution {
public:

    bool can(string s, int k){
        int a = 0, b = 0;
        for(int i = 0; i<s.size(); ++i){
            if(s[i] == '0') a++;
            else b++;
        }
        return a<=k || b<=k;
    }

    int countKConstraintSubstrings(string s, int k) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if(can(s.substr(i, j - i + 1), k)) ans++;
            }
        }
        return ans;
    }
};
