class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> A(n); for(int i = 0; i<n; ++i) A[i] = i;
        int i = 0;
        while(n>1){
            i+=k-1; i%=n;
            A.erase(A.begin()+i); --n;
        }
        return A[0]+1;
    }
};
