auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& A, vector<vector<int>>& Q) {
        int n = A.size(); vector<int> P(n);
        for(int i = 0; i<n-1; ++i){
            bool valid = ((A[i]&1) != (A[i+1]&1));
            P[i] += valid;  if(i) P[i] += P[i-1];
        }
        vector<bool> ans;
        for(auto it : Q)
            { ans.push_back( ((it[1] == 0? 0 : P[it[1]-1]) - (it[0] == 0? 0 : P[it[0]-1])) == it[1]-it[0]); }
        return ans;
    }
};
