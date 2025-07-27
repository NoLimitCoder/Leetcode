typedef long long ll;
class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size(), i;
        vector<ll> l(n+1), t(n+1), pre(n+1), suf(n+1);
        for(i = 0; i<n; ++i){l[i+1] = l[i] + (s[i]=='L');}
        for(i = n-1; i >= 0; --i) t[i] = t[i+1] + (s[i] == 'T');
        ll base = 0;
        for(i = 0; i<n; ++i){
            if(s[i] == 'C'){
                base += l[i] * t[i+1]; pre[i+1] = pre[i] + l[i];
            }
            else pre[i+1] = pre[i];
        }
        suf[n] = 0;
        for(i = n-1; i >= 0; --i)
            suf[i] = suf[i+1] + (s[i] == 'C'? t[i+1] : 0);
        ll e = 0;
        
        for(i = 0; i<=n; ++i){
            e = max({e,pre[i],suf[i],l[i]*t[i]});
        }
        return base + e;
    }
};
