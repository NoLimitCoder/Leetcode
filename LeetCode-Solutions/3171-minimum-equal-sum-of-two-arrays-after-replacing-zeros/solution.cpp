typedef long long ll;
class Solution {
public:
    ll minSum(vector<int>& A, vector<int>& B) {
        ll s1=0, s2=0, z1=0, z2=0;
        for(int i : A){s1 += i; if(i==0) z1++;} 
        for(int i : B){s2 += i; if(i==0) z2++;}
        if( (z1 == 0 && s2+z2 > s1) || (z2 == 0 && s1+z1 > s2)) return -1;
        else{
            return max(s1+z1,s2+z2);
        }
    }
};
