#define deb(x) cout << #x << ": " << x << '\n';
class Solution {
public:
    int minOperations(int k) {
        int mn = 2e9;
        if(k ==1) return 0;
        if(k == 2) return 1;
        for(double i = 1; i<=k; ++i){
            //mn = min(ceil(k/i)+(i-1),mn);
            int steps = ceil((double)k/i)-1 + (i-1);
            
            if(mn > steps) mn = steps;
            //deb(ceil(k/i)); deb(steps); deb(i); deb(mn);
        }
        return mn;
    }
};
