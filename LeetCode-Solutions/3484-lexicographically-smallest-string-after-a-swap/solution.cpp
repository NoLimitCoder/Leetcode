class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for(int i = 0; i<n-1; ++i){
            if( (((s[i]-'0')%2) == (s[i+1]-'0')%2)  && s[i]-'0' > s[i+1]-'0'){
            char tmp = s[i];
            s[i] = s[i+1]; s
            [i+1] = tmp;
            break;
            }
        }
        return s;
    }
};
