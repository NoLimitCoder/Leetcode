class Solution {
public:

bool check(char c, char t){
    if(c == '{') c = '}';
    if(c == '[') c = ']';
    if(c == '(') c = ')';
    return c == t;
}



    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i<s.size();++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }
            else{
                if(stk.size()==0){return false;}
                if(check(stk.top(),s[i])){
                    //cout<< stk.top() << ' ' << s[i] << '\n';
                    stk.pop(); continue;
                }
                else{return false;}
            }
        }
        return stk.size()==0;
    }
};
