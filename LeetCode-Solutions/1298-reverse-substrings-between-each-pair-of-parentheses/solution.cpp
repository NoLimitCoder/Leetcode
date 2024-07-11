auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:
    string reverseParentheses(string s) {
        string stk;
        for(int i = 0; i<s.size(); ++i){
            if(s[i] == ')'){
                string tmp = "";
                char c = stk.back();
                while(c != '('){
                    tmp += c;
                    stk.pop_back(); 
                    c = stk.back();
                } 
                stk.pop_back(); 
                stk += tmp;
            }
            else stk.push_back(s[i]);
        }
        return stk;
    }
};
