class Solution {
public:

    bool valid(char a, char b){
        int x = a-'a', y = b-'a';
        if( (x%26 == (y+1)%26) || (y%26 == (x+1)%26) ){
            return 1;
        }
        return 0;
    }
    
    string resultingString(string s) {
        stack<char>stk;
        for(int i = 0; i<s.size(); ++i){
            char c = s[i];
            if(stk.empty()) stk.push(c);
            else{
                bool flag = 1;
                while(!stk.empty() && valid(stk.top(),c)) {
                    stk.pop();
                    flag = 0;
                    if(stk.empty()) break;
                    c = stk.top();
                }
                if(flag)stk.push(c);
            }
        }
        string ans = "";
        while(!stk.empty()){
            ans += stk.top(); stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
