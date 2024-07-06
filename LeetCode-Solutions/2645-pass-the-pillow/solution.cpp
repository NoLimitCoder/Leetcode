class Solution {
public:
    int passThePillow(int n, int time) {
        int direction = 1, i = 1;
        while(time--){
            i += direction;
            if(i == n) direction = -1;
            if(i == 1) direction = 1;
        }
        return i;
    }
};
