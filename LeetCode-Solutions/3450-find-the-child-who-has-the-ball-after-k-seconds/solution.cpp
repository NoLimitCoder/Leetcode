class Solution {
public:
    int numberOfChild(int n, int k) {
        int i = 0;
        bool flag = 0;
        while(k--){
            if(i == n-1){flag = 1;}
            if(i == 0) flag = 0;
            
            
            if(!flag) i++;
            else i--;
        }
        return i;
    }
};
