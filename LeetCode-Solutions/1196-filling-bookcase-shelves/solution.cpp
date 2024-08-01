auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
typedef vector<vector<int>> VVI;
const int INF = 2e9;
class Solution {
public:

    int dp(int idx, int &w, VVI &B, vector<int>& DP){
        if(idx == B.size()) return 0;
        if(DP[idx] != -1) return DP[idx];
        int shelf_height = 0, shelf_width = 0, mn = INF;
        //start shelf in all reachable states
        for(int i = idx; i<B.size(); ++i){
            shelf_width += B[i][0];
            //early stopping
            if(shelf_width > w) break;
            //start new shelf at this idx
            shelf_height = max(shelf_height, B[i][1]);
            mn = min(mn, shelf_height + dp(i+1,w,B,DP));
        }
        return DP[idx] = mn;
    }


    int minHeightShelves(vector<vector<int>>& B, int w) {
        vector<int> DP(B.size(),-1);
        return dp(0,w,B,DP);
    }
};
