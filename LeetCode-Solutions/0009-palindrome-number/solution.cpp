class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        long long org = x;
        long long reverse = 0;
        //use mod 10 to get value at idx i
        while(x>0){
            long long number = x%10;

//       121
//      121 % 10 = 1
//      121 / 10 = 12
            reverse = reverse*10 + number;
            x/=10;
        }
        return reverse == org;
    }
};
