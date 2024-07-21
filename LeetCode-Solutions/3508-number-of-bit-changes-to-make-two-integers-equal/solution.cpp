class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        for(int i = 0; i<32; ++i){
            if( (k & (1<<i)) && !(n&(1<<i)) ) return -1;
            else if( !(k & (1<<i)) && (n&(1<<i)) ) ++ans;
        }
        return ans;
    }
};
