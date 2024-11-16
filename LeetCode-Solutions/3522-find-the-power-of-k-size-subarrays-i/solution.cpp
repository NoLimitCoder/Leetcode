auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:

    int check(vector<int> A){
        for(int i = 0; i<A.size()-1; ++i) if(A[i+1] != A[i]+1) return -1;
        return A[A.size()-1];
    }

    vector<int> resultsArray(vector<int>& V, int k) {
        vector<int> ans;
        for(int i = 0; i<=V.size()-k; ++i)
            { ans.push_back(check(vector<int>(V.begin()+i, V.begin()+i+k))); }
        return ans;
    }
};
