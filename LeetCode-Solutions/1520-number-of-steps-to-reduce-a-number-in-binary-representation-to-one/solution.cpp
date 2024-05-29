#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    int numSteps(string s) {
        int ans = 0, i = s.size()-1;
        bool carry = 0;
        while(i >= 0){
            if(i == 0 && s[i] == '1' && carry == 0) break;
            if((s[i] == '1' && carry == 0) || (carry == 1 && s[i] == '0')){
                ans+=2;
                i--;
                carry = 1;
            }
            else{
                ans++;
                i--;
            }
        }
        return ans;
    }
};
