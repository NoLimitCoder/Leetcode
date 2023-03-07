class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x!=0){
        int temp = x%10;
        x /= 10;
        if(ans > INT_MAX / 10 || (ans == INT_MAX/10 && temp > 7)) {ans = 0; break;}
        if(ans < INT_MIN / 10 || (ans == INT_MIN/10 && temp < -8)) {ans = 0; break;}
        ans = ans * 10 + temp;
        }
        //cout << INT_MAX << ' ' << INT_MIN << '\n';
    return ans;
    }
    
};
