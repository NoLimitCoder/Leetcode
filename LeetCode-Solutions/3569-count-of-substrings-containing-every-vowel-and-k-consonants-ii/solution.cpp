#define deb(x) cout << #x << ": " << x << '\n'
typedef long long ll;
class Solution {
public:

bool valid(vector<int> &mp, int k){
    return (mp['a'-'a'] && mp['e'-'a'] && mp['i'-'a'] && mp['o'-'a'] && mp['u'-'a'] && mp[26] == k);
}

    long long countOfSubstrings(string s, int k) {
        set<ll> st;
        vector<int> mp(27);
        ll n = s.size();
        st.insert(n);
        for(int i = 0; i<n; ++i){
            if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
            st.insert(i);
        }
       //for(auto it : st) cout << it << ' ';
        //cout << '\n';
        ll i = 0, j = 0, ans = 0;
        while(j < n){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                mp[s[j]-'a']++;
            else 
                mp[26]++;
            while(mp[26] > k){
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    mp[s[i]-'a']--;
                else 
                    mp[26]--;
                ++i;
            }
            //cout << i << ' ' << j << '\n';
            while(i<n && valid(mp,k)){
                ll pos = *st.upper_bound(j);
                //deb(pos);
                ans += (pos-j);
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    mp[s[i]-'a']--;
                else 
                    mp[26]--;
                ++i;
                //j = max(j,i);
            }
                ++j;
        }
        return ans;
    }

};

//"iqeaouqi"
//k = 2
