class Solution {
public:
    vector<vector<int>> permute(vector<int>& A) {
        vector<vector<int>> ans;
        sort(A.begin(), A.end());
        do{
            ans.push_back(A);
        }while(next_permutation(A.begin(), A.end()));
        return ans;
    }
};
