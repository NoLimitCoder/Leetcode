class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int mx = *max_element(a.begin(), a.end()), len = 0, n = a.size(), ans = 0;
        for(int i = 0; i<n; ++i){
            len = (a[i] == mx)? len+1 : 0;
            ans = max(ans, len);
        }
        return ans;
    }
};
