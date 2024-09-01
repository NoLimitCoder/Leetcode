class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int a = (c1[0] -'a')%2;
        int b = (c1[1] -'0')%2;
        int cc1 = 0;
        if(a == b) cc1 = 1;
        int a1 = (c2[0] -'a')%2;
        int b1 = (c2[1] -'0')%2;
        int cc2 = 0;
        if(a1 == b1) cc2 = 1;
        return cc1 == cc2;
    }
};
