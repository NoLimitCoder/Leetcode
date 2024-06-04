#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '

class Solution {
public:
    int getSum(int a, int b) {/*
        int a_bit = 0, b_bit = 0, carry = 0, ans = 0;
        int v = max(a,b);
        int msb = 0;
        while (v >>= 1) {msb++;}
        for(int i = 0; i<=msb; ++i){
            a_bit = ((a & (1<<i))? 1 : 0);
            b_bit = ((b & (1<<i))? 1 : 0);
            debl(a_bit); debl(b_bit); deb(carry);
            if(a_bit & b_bit & carry) {ans |= 1; ans = ans << 1; carry = 1; deb(1); continue;}
            if((a_bit & b_bit) || (a_bit & carry) || (carry & b_bit)) {deb(2); carry = 1; ans = ans << 1; continue;}
            if(a_bit || b_bit || carry) {deb(3); ans |= 1; carry = 0;}
            if(i!=msb)ans = ans << 1; 
        }
        return ans | carry;*/
        return a+b;
    }
};
