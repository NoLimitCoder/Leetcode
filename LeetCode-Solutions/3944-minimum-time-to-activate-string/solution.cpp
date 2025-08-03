typedef long long ll;
#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:
    
    bool can(int mid, vector<int>& order, int &k, ll &sum, int &n) {
        vector<char> pos(n,0);
        rep(i,mid+1) pos[order[i]] = 1;
        ll invalid = 0, len = 0;
        rep(i,n){
            if(pos[i]){invalid += (len*(len+1))/2; len = 0;}
            else ++len;
        }
        invalid += (len*(len+1))/2;
        return (sum - invalid) >= k;
    }
    
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        ll sum = (1LL*n*(n+1LL))/2LL;
        int lo = 0, hi = n-1, mid, ans = -1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(can(mid,order,k,sum,n)){ans = mid; hi = mid-1;}
            else lo = mid+1;
        }
        return ans;
    }
};
