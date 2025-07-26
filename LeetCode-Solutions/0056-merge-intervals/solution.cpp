class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
     sort(A.begin(), A.end()); vector<vector<int>> ans;
     for(auto it : A){
        if(ans.empty()) {ans.push_back(it); continue;}
        int l = it[0], r = it[1]; auto *end = &ans.back()[1];
        if(l > *end) ans.push_back(it);
        else *end = max(*end,r);
     }
     return ans;
    }
};
