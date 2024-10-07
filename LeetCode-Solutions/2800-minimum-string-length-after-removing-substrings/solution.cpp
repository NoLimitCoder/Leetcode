auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        int sp = 0;
        for(int i = 0; i<n; ++i){
            if(sp > 0 && ((s[sp-1] == 'A' && s[i] == 'B') || 
            (s[sp-1] == 'C' && s[i] == 'D')) ) {sp--;}
            else s[sp++] = s[i];
        }
        return sp;
    }
};
