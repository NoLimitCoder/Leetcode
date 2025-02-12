class Solution {
public:
    int bagOfTokensScore(vector<int>& A, int P) {
        sort(A.begin(), A.end());
        int mx_score = 0, cur_score = 0, n = A.size();
        int i = 0, j = n-1;
        while(i<=j){
            if(A[i] <= P) {P -= A[i++]; cur_score++;}
            else if(cur_score > 0){P+= A[j--]; cur_score--;}
            else{break;}
            mx_score = max(mx_score, cur_score);
        }
        return mx_score;
    }
};
