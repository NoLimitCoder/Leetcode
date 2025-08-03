class Solution {
public:
    bool isTrionic(vector<int>& A) {
        int n = A.size();
        for(int i = 1; i<n-1; ++i){
            for(int j = i+1; j<n-1; ++j){
                int tmp = 1;
                for(int k = 0; k<i; ++k) if(A[k+1] <= A[k]) tmp = 0;
                for(int k = i; k<j; ++k) if(A[k+1] >= A[k]) tmp = 0;
                for(int k = j; k< n-1; ++k) if(A[k+1] <= A[k]) tmp = 0;
                if(tmp) return 1;
            }
        }
        return 0;
    }
};
