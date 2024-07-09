#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& A) {
        int l=0, r =0, n = A.size();
        int sum = 0;
        int ans = INT_MAX;
        while(r < n){
            sum += A[r]; //debl(l); debl(r); deb(sum);
            while(sum >= target) {ans = min(ans,(r-l+1)); sum-=A[l++]; }
            ++r;

        }
        return ans == INT_MAX? 0 : ans;
    }
};
