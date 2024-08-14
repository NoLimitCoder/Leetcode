auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:

    bool can(vector<int>& A, int &k, int &x) {
        int contributions = 0;
        rep(i,A.size()){
            int pos = upper_bound(A.begin(), A.end(), x + A[i]) - A.begin(); pos--;
            if(pos == i) continue;
            contributions += (pos-i);
        }
        return contributions >= k;
    }

    int BS(vector<int>& A, int &k, int &mx){
        int lo = 0, hi = mx, mid, ans = -1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(can(A,k,mid)) {ans = mid; hi = mid-1;}
            else             {lo = mid+1;}
        }
        return ans;
    }

    int smallestDistancePair(vector<int>& A, int k) {
        //idea: first brute force to observe patterns
        /*
            int n = A.size();
            vector<int> bf;
            rep(i,n)
                for(int j = i+1; j<n; ++j){
                    int x = abs(A[i]-A[j]);
                    cout << A[i] << ", " << A[j] << ": " << x << '\n';
                    bf.push_back(x);
                }
            sort(bf.begin(), bf.end());
            return bf[k-1];
        */

        /*
            new idea: we can compute for each number how many pairs it can form that are smaller than
            some target x, ex: if we have 1,2,3,4,5 and x = 3, then number 1 has 3 pairs (1,2) (1,3) (1,4)
            that are smaller than 3, observe that we just need to find the upper bound (4) of this values
            which means that we can in log(n) find how many pairs are smaller than the target x when we fixate
            the number at i
            then, what we can do is, for each number, compute how many contributions they add when the given target is x
            now since the number of contributions can have 2 states, either < k or >= k, what we want is the smallest x 
            s.t. contributions >= k so we can apply BS on answer
        */
        sort(A.begin(), A.end()); 
        int mx = A[A.size()-1] - A[0];
        return BS(A,k,mx);
    }
};
