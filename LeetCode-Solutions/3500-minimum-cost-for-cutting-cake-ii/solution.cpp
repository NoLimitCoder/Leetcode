auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& H, vector<int>& V) {
        vector<pair<int,int>> A;
        for(auto it : H) A.push_back({it,0});
        for(auto it : V) A.push_back({it,1});
        sort(A.rbegin(), A.rend());
        long long x = 0, y = 0, ans = 0;
        for(int i = 0; i<A.size(); ++i){
            if(A[i].second == 0) {ans += (x+1) * A[i].first; ++y;}
            if(A[i].second == 1) {ans += (y+1) * A[i].first; ++x;}
        }
    return ans;
    }   
};
