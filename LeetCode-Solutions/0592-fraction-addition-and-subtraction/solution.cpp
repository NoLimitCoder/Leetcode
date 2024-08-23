auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
#define rep(i,n) for(int i = 0; i<n; ++i)
typedef long long ll;
class Solution {
public:

ll gcd(ll a, ll b) {return b? gcd(b, a%b) : a;}


struct fraction{
    ll sign, numerator, denominator;
};

    string fractionAddition(string s) {
        ll sign, numerator, denominator, n = s.size();
        vector<fraction> v;
        int i = 0;
        while (i < n){
            sign = 1;
            if (s[i] == '+' || s[i] == '-') {if (s[i] == '-') sign = -1; i++;}
            ll num = 0; while (i < n && isdigit(s[i])) { num = num * 10 + (s[i] - '0'); ++i; } 
            ++i;
            ll den = 0; while (i < n && isdigit(s[i])) { den = den * 10 + (s[i] - '0'); ++i; }
            v.push_back({sign,num,den});
        }
        fraction ans = {1,0,1};
        rep(i,v.size()){
            fraction cur = v[i];
            cur.numerator *= cur.sign;
            ans.numerator *= cur.denominator;
            cur.numerator *= ans.denominator;
            
            ans.numerator += cur.numerator;
            ans.denominator *= cur.denominator;
            ll cur_gcd = gcd( abs(ans.numerator), ans.denominator);
            ans.numerator /= cur_gcd;
            ans.denominator /= cur_gcd;

            //cout << v[i].sign << ' ' << v[i].numerator << ' ' 
            //<< v[i].denominator << '\n'; 
            //cout << ans.numerator << ' ' << ans.denominator << '\n';
        }
        string res = "";
        res += to_string(ans.numerator);
        res += "/";
        res += to_string(ans.denominator);
        return res;
    }
};
