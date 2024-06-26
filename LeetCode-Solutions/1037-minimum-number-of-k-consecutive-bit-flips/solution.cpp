#pragma GCC optimize("O3,unroll-loops")

class Solution {
public:
    int minKBitFlips(vector<int>& A, int k) {
        int ans = 0, n = A.size();
        vector<int> difference_array(n+1);
        int sweep_line_flip = 0;
        for(int i = 0; i<n; ++i){
            sweep_line_flip += difference_array[i]; sweep_line_flip %= 2;
            if(A[i] ^ sweep_line_flip == 0){
                if(i+k-1 >= n) return -1;
                difference_array[i] += 1; sweep_line_flip += 1; ans++;
                difference_array[i+k] -= 1;
            }
        }
        return ans;
    }
};
