class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        for(int i = 0; i<n; ++i){
            int x = A[i];
            for(int j = i+1; j<n; ++j){
                x ^= A[j];
                if(x == 0) ans+= (j-i);
            }
        }
        return ans;
    }
};

/*
2^
  0010

3^1
  0011
^ 0001
= 0010
*/
