typedef long long ll;
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& a) {
        ll ans = 0;
        map<int,int> mp;
        for(int i = 0; i<a.size(); ++i){a[i] = a[i]%24; mp[a[i]%24]++;}
        
        for(int i = 0; i<a.size(); ++i){
            ans += mp[ (24-a[i])%24 ];
            if(a[i] == (24-a[i])%24) ans--;
            //cout << a[i] << ',' << 24-a[i] << ',' << mp[a[i]] << ' ';
            mp[a[i]]--; mp[a[i]] = max(0,mp[a[i]]);
            
        }
        //cout << '\n';
        return ans;
    }
};
