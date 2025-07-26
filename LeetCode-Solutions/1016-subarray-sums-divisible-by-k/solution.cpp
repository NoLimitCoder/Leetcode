class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        int n = A.size();
        for(int i = 0; i<n; ++i){ 
            if(A[i] < 0) A[i] += ((abs(A[i])/k)+1)*k; 
            A[i] %= k;
        }
        vector<int> P(n+1);
        for(int i = 0; i<n; ++i){
            P[i] = A[i]; if(i) P[i] += P[i-1];
            P[i] %= k;
        }
        map<int,int> mp; mp[0] = 1;
        int ans = 0;
        for(int i = 0; i<n; ++i){
            ans += mp[P[i]];
            mp[P[i]]++;
        }
        return ans;
    }
};
