auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size(), ans = 0;
        string stk;
        for(int i = 0; i<n; ++i){
           if(stk.size() == 0) {stk+=s[i]; continue;}
            int top = stk.size()-1;
            if(x > y){
                if(stk[top] == 'a' && s[i] == 'b'){
                    ans += x;
                    stk.pop_back();
                    continue;
                }
            }
            else{
                if(stk[top] == 'b' && s[i] == 'a'){
                    ans += y;
                    stk.pop_back();
                    continue;
                }
            }

        stk+=s[i];
        }
        string s2 = stk;
        stk = "";
        for(int i = 0; i<s2.size(); ++i){
            if(stk.size() == 0) {stk+=s2[i]; continue;}
            int top = stk.size()-1;
            if(x < y){
                if(stk[top] == 'a' && s2[i] == 'b'){
                    ans += x;
                    stk.pop_back();
                    continue;
                }
            }
            else{
                if(stk[top] == 'b' && s2[i] == 'a'){
                    ans += y;
                    stk.pop_back();
                    continue;
                }
            }
        stk+=s2[i];
        }
        return ans;
    }
};
