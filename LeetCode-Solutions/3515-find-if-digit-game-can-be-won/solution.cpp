class Solution {
public:
    bool canAliceWin(vector<int>& A) {
        //choice one
        int a = 0, b = 0;
        for(int i = 0; i<A.size(); ++i){
            if(A[i]>=10) a+= A[i];
            else b+=A[i];
        }
        if(a > b) return 1;
        a = 0, b = 0;
        for(int i = 0; i<A.size(); ++i){
            if(A[i]<10) a+= A[i];
            else b+=A[i];
        }
        if(a > b) return 1;
        return 0;
    }
};
