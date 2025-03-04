class Solution {
public:
    vector<int> pivotArray(vector<int>& A, int p) {
        vector<int> ans;
        int cnt = 0;
        for(int i = 0; i<A.size(); ++i){
            if(A[i] < p) ans.push_back(A[i]);
            if(A[i] == p)cnt++;
        }
        while(cnt--)ans.push_back(p);
        for(int i = 0; i<A.size(); ++i){
            if(A[i] > p) ans.push_back(A[i]);
        }
        return ans;
    }
};
