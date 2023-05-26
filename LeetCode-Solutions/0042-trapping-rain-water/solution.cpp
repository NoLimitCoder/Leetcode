class Solution {
public:
    int trap(vector<int>& height) {
        //idea: go from left until max tower and from right until max tower and sum up the water 
        //linear scan to get highest tower:
        int n = height.size();
        int maxTowerIndex = 0, maxTowerHeight = -1;
        for(int i = 0; i< n; ++i){
            if(height[i] > maxTowerHeight){
                maxTowerHeight = height[i];
                maxTowerIndex = i;
            }
        }
        
//LeftSide
        int waterSumLeft = 0, curMax = 0, curDiff = 0;
        for(int i = 0; i <= maxTowerIndex; ++i){
            if(height[i] > curMax){
                curMax = height[i];
                waterSumLeft += curDiff;
                curDiff = 0;
            }
            else{
                curDiff += abs(curMax - height[i]);
            }
        }
        //printf("waterSumLeft: %d, maxTowerIndex: %d, curMax: %d\n",waterSumLeft,maxTowerIndex,curMax);

//RightSide
        int waterSumRight = 0;
        curMax = 0, curDiff = 0;
        for(int i = n-1; i >= maxTowerIndex; --i){
            if(height[i] >= curMax){
                curMax = height[i];
                waterSumRight += curDiff;
                curDiff = 0;
            }
            else{
                curDiff += abs(curMax - height[i]);
            }
        }
        //printf("waterSumRight: %d, maxTowerIndex: %d, curMax: %d\n",waterSumRight,maxTowerIndex,curMax);
        return waterSumRight + waterSumLeft;
    }
};
