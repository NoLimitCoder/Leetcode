class Solution {
public:
    int numWaterBottles(int n, int m) {
      int ans = n;
      while(n/m > 0){
        int extra = n%m;
        n /= m;
        ans += n;
        n += extra;
      }
      return ans;
    }
};
