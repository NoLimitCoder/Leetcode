class Solution {
public:
    long long coloredCells(int n) {
        return pow(n,2LL) + pow(n-1LL,2LL);
    }
};
