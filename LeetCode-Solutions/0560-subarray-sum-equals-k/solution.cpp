class Solution {
public:
    int subarraySum(vector<int>& A, int k) {
        //prefix sum 2 pointers with map
        int n = A.size();
        vector<int> P(n);
        for(int i = 0; i<n; ++i){
            P[i] = A[i];
            if(i>0) P[i] += P[i-1];
        }
        //P[j] - P[i] = sum -> P[j] - sum = P[i]
        unordered_map<int,int>mp; mp[0] = 1;
        int ans = 0;
        for(int j = 0; j<n; ++j){
            if(mp.find(P[j]-k) != mp.end() ){
                ans += mp[P[j]-k];
            }
            mp[P[j]]++;
        }
        return ans;
    }
};
