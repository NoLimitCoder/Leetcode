class Solution {
public:
    bool isValid(string s) {
     stack<char>stk;
     for(int i = 0; i< s.size(); ++i){
         if(s[i] == '{' || s[i] == '(' || s[i] == '['){
             stk.push(s[i]);
             continue;
         }
         else{
             if(stk.empty()){return false;}
             char top = stk.top();
             if(top == '{' && s[i] == '}'){
                 stk.pop();
             }
             else if(top == '(' && s[i] == ')'){
                 stk.pop();
            }
            else if(top == '[' && s[i] == ']'){
                stk.pop();
            }
            else {
                return false;
            }
        }
     }
    return stk.empty();
    }
};
