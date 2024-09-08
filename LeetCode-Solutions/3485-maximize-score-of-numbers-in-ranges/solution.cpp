#define deb(x) cout << #x << ": " << x << '\n'
typedef long long ll;
class Solution {
public:

bool can(int mid, vector<int> A, int d) {
    for(int i = 1; i<A.size(); ++i){
        int cur = A[i] - A[i-1];
        if(cur >= mid) continue;
        else{
            if(A[i]+d - A[i-1] >= mid){
                A[i] += (mid + A[i-1] - A[i]);
            }
            else{return 0;}
        }
    }
    return 1;
}


int bs(vector<int>& A, int d) {
    int hi = 2e9, lo = 0, mid, ans = 0;
    while(lo<=hi){
        mid = lo + (hi-lo)/2;
        //cout << mid << '\n';
        if(!can(mid,A,d)) {hi = mid-1;}
        else {ans = mid; lo = mid+1;}
    }
    return ans;
}

    int maxPossibleScore(vector<int>& A, int d) {
        int n = A.size();
        sort(A.begin(), A.end());
        int ans = bs(A, d);
        return ans;
    }
};
//0 3 6
