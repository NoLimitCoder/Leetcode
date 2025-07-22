class Solution {
public:
    int maximumUniqueSubarray(vector<int>& A) {
        int l = 0, n = A.size(); long long ans = 0, sum = 0;
        map<int,int>mp;
        for(int r = 0; r<n; ++r){
            while(mp[A[r]] > 0){sum -= A[l]; mp[A[l++]]--;}
            mp[A[r]]++;
            sum+=A[r];
            ans = max(ans, sum);
        }
        return ans;
    }
};
