typedef long long ll;
#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size(); vector<int> d(n);
        for(int i=0;   i<n; ++i) { d[i] = target[i] - nums[i]; cout << d[i] << ' ';} cout << '\n';
        for(int i=n-1; i>0; --i) { d[i] -= d[i-1]; }
        ll s = 0, t = 0;
        for(int i=0; i<n; ++i){
            if(d[i] >= 0) s += d[i];
            else t += d[i];
            cout << d[i] << ' ';
        } cout << '\n';
        return max(s, abs(t));
    }
};
