#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    bool can(int guess, int m, vector<int>&A){
        int cur = A[0]; m--;
        for(int i = 1; i<A.size(); ++i){
            if(abs(A[i]-cur) >= guess){m--; cur = A[i];}
            if(m==0) break;
        }
        return m == 0;
    }

    int BS(int n, int m, vector<int>& A){
        int lo = 0, hi = n, mid, ans = -1;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(can(mid, m, A)){lo = mid+1; ans = mid;}
            else {hi = mid-1;}
        }
        return ans;
    }

    int maxDistance(vector<int>& A, int m) {
        sort(A.begin(), A.end());
        return BS(*max_element(A.begin(), A.end()), m, A);
        
    }
};
