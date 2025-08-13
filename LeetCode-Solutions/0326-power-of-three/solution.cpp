class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return 0;
        bool f = 1;
        while(n > 1){if(n % 3 != 0) f = 0; n/=3;}
        return f;
    }
};
