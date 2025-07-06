class Solution {
typedef long long ll;
public:
    
    int minMoves(int sx, int sy, int tx, int ty) {
    long long x = tx, y = ty;
    int moves = 0;
    while (x != sx || y != sy) {
        if (x < sx || y < sy) 
            return -1;

        if (x >= y) {
            long long a = x, b = y;
            if (b == 0 || a >= 2*b) {
                if (a & 1) return -1;  
                x = a >> 1;
            } else {
                if (a == b) {
                    if (y - b >= sy)       y -= b;
                    else                    x -= b;
                } else {
                    x = a - b;
                }
            }
        } else {
            long long a = y, b = x;
            if (b == 0 || a >= 2*b) {
                if (a & 1) return -1;
                y = a >> 1;
            } else {
                if (a == b) {
                    if (x - b >= sx)       x -= b;
                    else                    y -= b;
                } else {
                    y = a - b;
                }
            }
        }

        ++moves;
    }
    return moves;
}



};
