#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
class Solution {
public:
typedef long long ll;

    int maxSubArray(vector<int>& A) {
        ll ans = A[0];
        ll sum = A[0];
        for(int i = 1; i<A.size(); ++i){
            if(sum < 0) sum = 0;
            sum += A[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};
