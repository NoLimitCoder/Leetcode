class Solution {
public:
    int maxSubarrayLength(vector<int>& A, int k) {
        map<int,int> mp; int n= A.size();
        int ans = 0;
        int l = 0;
        for(int r = 0; r<n; ++r){
            while(mp[A[r]] >= k) mp[A[l++]]--;
            mp[A[r]]++;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
