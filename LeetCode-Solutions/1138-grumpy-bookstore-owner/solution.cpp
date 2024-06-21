#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    int maxSatisfied(vector<int>& C, vector<int>& G, int k) {
        int sum = 0, mx = 0, n = C.size();
        for(int i = 0; i<n; ++i){ if(!G[i]) sum += C[i]; }
        int i = 0, j = 0;
        while(i < k) {if(G[i]){sum += C[i];} ++i;}
        mx = max(mx,sum);
        while(i<n){
            if(G[j]) sum -= C[j];
            if(G[i]) sum += C[i];
            mx = max(mx,sum);
            i++; j++;
        }
        return mx;
    }
};
