class Solution {
public:
    int findLHS(vector<int>& A) {
        //idea: suffix sum
        int n = A.size();
        unordered_map<int,int> mp;
        int mx = 0;
        for(int i = n-1; i >= 0; --i) mp[A[i]]++;
        for(int i = 0; i<n; ++i){
            if(mp[A[i]+1]) mx = max(mx, mp[A[i]] + mp[A[i]+1]);
            if(mp[A[i]-1]) mx = max(mx, mp[A[i]] + mp[A[i]-1]);
            mp[A[i]]--;
        }
    return mx;
    }
};
