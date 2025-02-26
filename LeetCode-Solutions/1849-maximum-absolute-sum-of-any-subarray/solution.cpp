#pragma GCC optimize(O3,"unroll-loops")
auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    int maxAbsoluteSum(vector<int>& A) {
     //idea kadane's algo in min max?
     int n = A.size(), mx = A[0], ans1 = 0, ans2 = 0;
     for(int &i : A){
        if(ans1 < 0) ans1 = 0; if(ans2 > 0) ans2 = 0;
        ans1 += i; ans2 += i;
        mx = max({mx,ans1,abs(ans2)});
     }
        return mx;
    }
};
