class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>> A(n);
        for(int i = 0; i<n; ++i){A[i] = {difficulty[i], profit[i]};}
        sort(A.begin(), A.end());
        int mx = 0;
        for(int i = 0; i<n; ++i){
            difficulty[i] = A[i].first; profit[i] = A[i].second;
            if(profit[i] < mx) profit[i] = mx;
            else mx = profit[i];
        }
        int ans = 0;
        for(int w : worker){
            int p = upper_bound(difficulty.begin(), difficulty.end(), w) - difficulty.begin(); if(p) p--;
            if(difficulty[p] > w)continue;
            ans += profit[p];
        }
        return ans;
    }
};
