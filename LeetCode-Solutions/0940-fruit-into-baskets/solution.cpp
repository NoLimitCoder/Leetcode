#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '
class Solution {
public:
    int totalFruit(vector<int>& A) {
        int n = A.size(), l = 0, ans = 1;
        unordered_map<int,int> mp;
        for(int r = 0; r<n; ++r){
            mp[A[r]]++;
            while(mp.size() > 2) {mp[A[l]]--; if(mp[A[l]] == 0) mp.erase(A[l]); ++l;}
           // debl(l); debl(r); debl(r-l+1); deb(mp.size());
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
