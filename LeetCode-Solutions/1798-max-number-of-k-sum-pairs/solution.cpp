class Solution {
public:
    int maxOperations(vector<int>& A, int k) {
        int n = A.size();
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0; i<n; ++i){
            if(mp.find(k-A[i]) != mp.end() && mp[k-A[i]] > 0){
                ans++; mp[k-A[i]]--;
            }
            else{
                mp[A[i]]++;
            }
        }
        return ans;
    }
};
