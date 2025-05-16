class Solution {
public:
    bool fCheck(int a, int b){ return (a && b) || !a; }
    bool pCheck(int a, int b){ return b <= a; }
    bool dCheck(int a, int b){ return b <= a; }
    vector<int> filterRestaurants(vector<vector<int>>& A, int f, int p, int d) {
        vector<vector<int>> ans(0);
        for(int i = 0; i<A.size(); ++i){
            //cond check
            if(fCheck(f,A[i][2]) && pCheck(p,A[i][3]) && dCheck(d,A[i][4])){
                ans.push_back(A[i]);
            }
        }
        //0 -> id | 1 -> rating | 2 -> f | 3 -> p |4-> d
        sort(ans.begin(), ans.end(), [](const auto &a, const auto &b){
            return a[1] == b[1]? a[0] > b[0] : a[1] > b[1];
        });
        vector<int> ans2;
        for(auto it : ans) ans2.push_back(it[0]);
        return ans2;
    }
};
