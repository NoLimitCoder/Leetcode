typedef long long ll;
class Solution {
public:
    ll maximumTripletValue(vector<int>& A) {
        ll ans = 0;
        int n = A.size();
        for(int i = 0; i<n; ++i){
            for(int j = i + 1; j <n; ++j){
                for(int k = j + 1; k <n; ++k){
                    ans = max(ans, ((A[i] - A[j])*1LL) * A[k]*1LL) ;
                }
            }
        }
        return ans;
    }
};
