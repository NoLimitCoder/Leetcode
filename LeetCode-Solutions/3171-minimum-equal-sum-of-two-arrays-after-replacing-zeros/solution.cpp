typedef long long ll;
class Solution {
public:
    long long minSum(vector<int>& A, vector<int>& B) {
        ll s1 = 0, s2 = 0, z1 = 0, z2 = 0;
        for(ll i : A) {if(!i) z1++; s1+=i;}
        for(ll i : B) {if(!i) z2++; s2+=i;}
        if( (!z1 && s1+z1 < s2+z2) || (!z2 && s2+z2 < s1+z1)) return -1;
        return max(s1+z1,s2+z2);
    }
};
