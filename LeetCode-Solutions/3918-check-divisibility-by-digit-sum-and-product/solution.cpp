class Solution {
public:
    bool checkDivisibility(int n) {
        int d = 0, p =1;
        int tmp = n;
        while(tmp > 0) {
            d+= tmp%10;
            p*= tmp%10;
             tmp/=10;
            }
        return (n%(d+p) == 0);
    }
};
