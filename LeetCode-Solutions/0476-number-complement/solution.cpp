class Solution {
public:
    int findComplement(int num) {
        int x = num;
        int idx = 0;
        while(x){++idx; x>>=1;}
        for(int i = 0; i<idx; ++i){num ^= (1<<i);}
        return num;
    }
};
