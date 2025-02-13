class Solution {
public:
    int strStr(string s, string p) {
        int m = p.size(), n = s.size(); vector<int> LPS(m,0);
        //kmp
        for(int i = 1, j = 0; i<m;){ p[i]==p[j]? LPS[i++] = ++j : j? j = LPS[j-1] : ++i; }
        //search
        for(int i = 0, j = 0; i<n;){ s[i]==p[j]? i++, ++j : j? j = LPS[j-1] : ++i; 
            //if(j==m) {cout << i-m << '\n'; j = LPS[j-1]; }
            if(j==m) return i-m;
        }
        return -1;
    }
};
