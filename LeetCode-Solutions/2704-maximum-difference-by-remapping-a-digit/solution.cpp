class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num), mx = s, mn = s; int i = 0;
        while(s[i]=='9' && i< s.length()-1) i += 1;
        for(char& ch : mx) if(ch == s[i]) ch = '9';
        for(char& ch : mn) if(ch == s[0]) ch = '0';
        return stoi(mx) - stoi(mn);
    }
};
