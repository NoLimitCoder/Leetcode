class Solution {
public:
    int minBitFlips(int a, int b) {
        int c = a ^ b;
        return __builtin_popcount(c);
    }
};
