#define deb(x) cout << #x << ": " << x << '\n';

class Solution {
public:
    int myAtoi(string s) {
        int j = 0;
        while((s[j] == ' ')&& j < s.size() )
         {j++;}
        int i = j;
        int sign = 0;
        if(s[i] == '-') {sign = -1; i++;}
        else if(s[i] == '+'){sign = 1; i++;}
        else if(s[i] >= '0' && s[i] <= '9') {sign = 1;}
        else {return 0;}
        int ans = 0;
        while(s[i] == '0' && i < s.size()){
            i++;
            deb(s[i]); deb(i);
        }
        while(i < s.size()){
            if(s[i] < '0' || s[i] > '9') break;
            int temp = (int)(s[i] - '0');
        if(ans > INT_MAX / 10 && sign == 1) 
            {deb(ans);ans = INT_MAX; break;}

        if(ans > INT_MAX / 10 && sign == -1) 
            {deb(ans);ans = INT_MIN; break;}

        if(ans == INT_MAX/10 && temp > 7)
            {ans = (sign == 1)? INT_MAX : INT_MIN; break;}
            ans = ans * 10 + temp;
            i++;
        }
        return ans<0? ans : ans * sign;
    }
};
