class Solution {
public:

    int minimumCost(int m, int n, vector<int>& H, vector<int>& V) {
        vector<pair<int,int>> A;
        for(auto it : H) A.push_back({it,0});
        for(auto it : V) A.push_back({it,1});
        sort(A.begin(), A.end());
        int x = 0, y = 0;
        int ans = 0;
        for(int i = A.size()-1; i>=0; --i){
            if(A[i].second == 0) {ans += (x+1) * A[i].first; ++y;}
            if(A[i].second == 1) {ans += (y+1) * A[i].first; ++x;}
        }
    return ans;
    }   
};
