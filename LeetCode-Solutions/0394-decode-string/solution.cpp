class Solution {
public:
    string decodeString2(string& s, int& i) {
        string ans;
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i])) {ans += s[i++];}
            else {
                int n = 0; while (i < s.length() && isdigit(s[i])) {n = n * 10 + s[i++] - '0';}
                ++i; string tmp = decodeString2(s, i); ++i;
                for(int j = 0; j<n; ++j) {ans += tmp;}
            }
        }
        return ans;
    }

    string decodeString(string s) {
        int i = 0; return decodeString2(s, i);
    }
};
