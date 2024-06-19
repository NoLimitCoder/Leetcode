#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:

    bool can(vector<int>& A, int &m, int &k, int &guess){
        int window_size = 0, bouquets = 0;
        for(int i = 0; i<A.size(); ++i){
            if(A[i] <= guess){window_size++;}
            else{window_size = 0;}
            if(window_size == k) {bouquets++; window_size = 0;}
        }
        return bouquets >= m;
    }

    int BS(vector<int>& A, int &m, int &k, int &mx){
        int lo = 1, hi = mx, mid, ans = -1;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(can(A,m,k,mid)){hi = mid-1; ans = mid;}
            else {lo = mid+1;}
        }
        return ans;
    }

    int minDays(vector<int>& A, int m, int k) {
        return BS(A,m,k,*max_element(A.begin(), A.end()));
    }
};
