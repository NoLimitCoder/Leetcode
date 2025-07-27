#define rep(i,n) for(int i=0;i<n;i++)
typedef double ld;
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& p){
        
        int n = p.size();
        vector<pair<ld,ld>> a(n);
        ld x=0,y=0;
        rep(i,n){
            a[i] = {p[i][0], p[i][1]};
            x += a[i].first; y += a[i].second;
        }
        x/=n; y/=n;
        auto f = [&](ld X, ld Y){
            ld s=0;
            for(auto& v:a) s+=hypot(X-v.first, Y-v.second);
            return s;
        };
        const ld A=0.5, B=0.8, TOL=1e-7;
        ld fx = f(x,y);
        rep(it,2000){
            ld gx=0, gy=0;
            rep(i,n){
                ld dx = x - a[i].first, dy = y - a[i].second;
                ld d = hypot(dx,dy);
                if(d>1e-12) gx+=dx/d, gy+=dy/d;
            }
            if(gx*gx+gy*gy < 1e-12) break;
            ld t=1;
            while(f(x-t*gx, y-t*gy) > fx - A*t*(gx*gx+gy*gy)) t*=B;
            x -= t*gx; 
            y -= t*gy;
            ld nf = f(x,y);
            if(fx-nf < TOL) break;
            fx = nf;
        }
        return fx;
    }
};

