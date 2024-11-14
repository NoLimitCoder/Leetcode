auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        long long ans = 0; sort(v.begin(), v.end());
         for (int i = 0; i < v.size(); ++i) 
            ans += (upper_bound(v.begin()+i+1,v.end(), upper-v[i])) - (lower_bound(v.begin()+i+1,v.end(), lower-v[i]));
        return ans;
    }
};
