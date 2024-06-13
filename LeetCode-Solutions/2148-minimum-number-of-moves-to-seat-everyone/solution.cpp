class Solution {
public:
    int minMovesToSeat(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end()); sort(B.begin(), B.end());
        int moves = 0;
        for(int i = 0; i<A.size(); ++i){
            moves += abs(A[i]-B[i]);
        }
        return moves;
    }
};
