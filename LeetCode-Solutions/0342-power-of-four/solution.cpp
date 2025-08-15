class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return 0;
        bool f = 1;
        while(n>1){if(n%4 != 0) f = 0; n/=4;}
        return f;
    }
};
