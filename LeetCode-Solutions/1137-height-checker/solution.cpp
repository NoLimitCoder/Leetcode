class Solution {
public:
    int heightChecker(vector<int>& A) {
        vector<int> B = A;
        sort(B.begin(), B.end());
        int ans = 0;
        for(int i = 0; i<A.size(); ++i){
            if(A[i] != B[i])ans++;
        }
        return ans;
    }
};
