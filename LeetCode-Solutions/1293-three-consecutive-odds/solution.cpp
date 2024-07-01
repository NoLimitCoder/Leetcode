class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& A) {
        for(int i = 2; i<A.size(); ++i){
            if( (A[i]&1) && (A[i-1]&1) && (A[i-2]&1) ) return true;
        }

        return false;
    }
};
