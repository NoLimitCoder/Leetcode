class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, A[3];
        for(int num : nums) ++A[num];
        while(A[0]--)nums[i++]=0;
        while(A[1]--)nums[i++]=1;
        while(A[2]--)nums[i++]=2;
    }
};
