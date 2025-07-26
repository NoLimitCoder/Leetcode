class Solution {
public:
    int findDuplicate(vector<int>& A) {
        for(int i = 0; i<A.size(); ++i){
            int idx = abs(A[i]);
            if(A[idx] < 0) return idx;
            A[idx] = -A[idx];
        }
        return -1;
    }
};
