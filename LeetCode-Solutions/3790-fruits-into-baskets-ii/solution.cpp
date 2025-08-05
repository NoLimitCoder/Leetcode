class Solution {
public:
    int numOfUnplacedFruits(vector<int>& A, vector<int>& B) {
        int ans = 0;
        for(int i = 0; i<A.size(); ++i){
            for(int j = 0; j<B.size(); ++j){
                if(B[j] >= A[i]) {++ans; B[j] = 0; break;}
            }
        }
        return A.size()-ans;
    }
};
