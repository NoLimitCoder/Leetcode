class Solution {
public:

    int maxHeightOfTriangle(int r, int b) {
        int ans = 0;
        int ht = 0;
        int red = r, blue = b;
        while(red>=0 && blue >= 0){
            ht++;
            red -= ht;
            if(red < 0) {ht--; break;}
            ht++;
            blue -= ht; 
            if(blue < 0) {ht--; break;}
        }
        ans = max(ans,ht);
        ht = 0;
        red = b, blue = r;
        while(red>=0 && blue >= 0){
            //cout << ht << ' ';
            ht++;
            red -= ht;
            if(red < 0) {ht--; break;}
            //cout << ht << ' ';
            ht++;
            blue -= ht; 
            if(blue < 0) {ht--; break;}
            //cout << ht << '\n';
        }
        return max(ans,ht);
    }
};
