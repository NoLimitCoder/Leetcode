class Solution {
public:

    bool check(string &s, string &p){
        for(int i = 0; i<p.size(); ++i)
            { if( (p[i] == 'I' && s[i] > s[i+1]) || (p[i] == 'D' && s[i] < s[i+1]) ) return 0; }
        return 1;
    }

    string smallestNumber(string p) {
        string s = "123456789"; s = s.substr(0,p.size()+1);
        do{
            if(check(s,p)) return s;
        } while(next_permutation(s.begin(), s.end()));
        return "";
    }
};
