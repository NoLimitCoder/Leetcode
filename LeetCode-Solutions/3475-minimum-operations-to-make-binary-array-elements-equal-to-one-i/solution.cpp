class Solution {
public:
    int minOperations(vector<int>& A) {
        //sweep line
        //0 1 2  3 4
        //1 1 1 -1
        int n = A.size();
        vector<int> df(n+1);
        int ans = 0;
        for(int i = 0; i<n; ++i){
            if(i>0) df[i] += df[i-1];
            int bit = df[i]%2;
            if( (A[i]^bit) == 0){
                if(i+3-1 >= n) return -1;
                ans++;
                df[i] += 1;
                df[3+i] -= 1;
            }
        }
        return ans;
    }
};
