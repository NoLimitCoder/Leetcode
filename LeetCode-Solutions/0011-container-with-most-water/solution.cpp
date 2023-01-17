class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int)height.size();
        int i = 0, j = n-1;
        int mx = 0;
        while(i <= j){
            int h = min(height[i],height[j]);
            int w = j-i;
            mx = max(mx,h*(w));
            //cout << "i: " << height[i] << " j: " << height[j] << " h: " << h << " w: " << w << "mx: "<<mx<<endl;
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return mx;
    }
};
