class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i = 0; i<tokens.size(); ++i){
            if(tokens[i] == "+"||tokens[i] == "-"||tokens[i] == "*"||tokens[i] == "/"){
                int a, b; 
                b = stk.top(); stk.pop();
                a = stk.top(); stk.pop();
                int temp = 0;
                if(tokens[i] == "+"){temp = a+b;}
                else if(tokens[i] == "-"){temp = a-b;}
                else if(tokens[i] == "*"){temp = a*b;}
                else if(tokens[i] == "/"){temp = a/b;}
                stk.push(temp);
                //printf("a: %d, b: %d, temp: %d\n",a,b,temp);
            }
            else{
                int temp = stoi(tokens[i]);
                stk.push(temp);
            }
        }
        return stk.top();
    }
};
