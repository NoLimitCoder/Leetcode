class Solution {
public:
    long long gauss(int x) {
        if (x < 0) return 0;
        return (long)x * (x - 1) / 2;
    }

    int distributeCandies(int n, int limit) {
        return gauss(n + 2) - 3 * gauss(n - limit + 1) +
               3 * gauss(n - (limit + 1) * 2 + 2) - gauss(n - 3 * (limit + 1) + 2);
    }
};
