class Solution {
public:
    bool isHappy(int n) {
       int j = 0, num = 0; while(n > 1 && j < 7){num = 0; while(n > 0){num += (n%10)*(n%10); n/=10;} n += num; j++;} return n == 1;
    }
};
