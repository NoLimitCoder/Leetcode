class Solution {
public:
    bool isZeroArray(vector<int>& A, vector<vector<int>>& Q) {
        int n = A.size();
        vector<int> diff(n+5);
        for(auto it : Q){
            diff[it[0]]--;
            diff[it[1]+1]++;
        }
        for(int i = 0; i<n; ++i){
            if(i) diff[i] += diff[i-1];
            A[i] += diff[i];
            if(A[i] > 0) return 0;
        }
    return 1;
    }
};
