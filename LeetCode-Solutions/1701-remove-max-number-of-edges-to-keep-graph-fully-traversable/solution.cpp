#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    struct DSU{
        int n; vector<int> p, sz;
        DSU(int n): n(n), p(n), sz(n,1) {for(int i = 0; i<n;++i)p[i]=i;}
        int size(){return n;}
        int get(int x){return p[x]==x? x : p[x] = get(p[x]);}
        bool unite(int x, int y){
            x = get(x); y=get(y); if(x==y) return 0;
            if(sz[x]<sz[y])swap(x,y);
            sz[x]+=sz[y]; p[y]= x; --n; return 1;
        }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& E) {
       //idea: use 2 disjoint sets, check for the return value of unite, those are the extra components 
        DSU A(n+1), B(n+1);
        int count = 0;
        sort(E.begin(), E.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        for(int i = 0; i<E.size(); ++i){
            int type = E[i][0], u = E[i][1], v = E[i][2];
            if(type == 1)
                { if(!A.unite(u,v)) count++; }
            else if (type==2)
                { if(!B.unite(u,v)) count++; }
            else{
                //since we process them in order with #3 first, if A doesn't need this connection, then B doesn't need it either
                bool f = 0;
                if( !A.unite(u,v) ) f = 1;
                if( !B.unite(u,v) ) f = 1;
                if(f) count++;
            }
        }
        if(A.size()-1 != 1 || B.size()-1 != 1) return -1;
        return count;
    }
};
