class Solution {
public:

    bool can(int &mid, vector<int> &A, vector<vector<int>> &Q){
        int n = A.size();
        vector<int> diff(n+2,0);
        for(int i = 0; i<mid; ++i){
            diff[Q[i][0]  ] -= Q[i][2];
            diff[Q[i][1]+1] += Q[i][2];
        }
        for(int i = 0; i<n; ++i){
            if(i) diff[i] += diff[i-1];
            if(A[i] + diff[i] > 0) return 0;
        }
        return 1;
    }


    int minZeroArray(vector<int>& A, vector<vector<int>>& Q) {
        int lo = 0, hi = Q.size(), mid, ans = -1;
        while(lo <= hi){
            mid = (hi+lo)/2;
            if(can(mid,A,Q)){hi = mid-1; ans = mid;}
            else lo = mid+1;
        }
        return ans;
    }
};
