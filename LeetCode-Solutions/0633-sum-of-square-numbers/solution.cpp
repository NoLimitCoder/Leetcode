class Solution {
public:
    bool judgeSquareSum(int c) {
     for(long long a = 0, b; a*a <= c; ++a){
        b = sqrt(c-a*a);
        if(b*b == c-a*a) return true;
     }
     return false;
    }
};
