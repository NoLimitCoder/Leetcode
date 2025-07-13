typedef long long ll;

char find_minc(int i, ll k, string &s, vector<ll> & gen){
    char c = s[i-1];
    if(c=='*') return find_minc(i-1,k,s,gen);
    else if(c == '#'){ll h = gen[i-1]; return find_minc(i-1, (k < h? k : k-h),s,gen); }
    else if(c == '%'){ll h = gen[i-1]; return find_minc(i-1,h-1-k,s,gen);}
    else return k == gen[i]-1? c : find_minc(i-1,k,s,gen);
}

class Solution {
public:
    char processStr(string s, long long k) {
       int n = s.size(); 
        ll MAX = 4e18;
        vector<ll> gen(n+1); gen[0] = 0;
        for(int i = 1; i<=n; ++i){
            char c = s[i-1];
            if(c=='*') gen[i] = gen[i-1]>0? gen[i-1]-1 : 0;
            else if(c == '#') gen[i] = min(MAX, gen[i-1]*2);
            else if(c == '%') gen[i] = gen[i-1];
            else gen[i] = min(MAX, gen[i-1]+1);
        }
        if(k < 0 || k >= gen[n]) return '.';
        return find_minc(n,k,s,gen);
    }
};
