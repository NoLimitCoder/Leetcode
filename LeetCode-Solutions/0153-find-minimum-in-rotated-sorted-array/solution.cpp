class Solution {
public:

int bs(vector<int>& nums){
    int n = nums.size();
    int lo = 0, hi = n-1, mid = 0;
    while(lo<hi){
        mid = lo + (hi-lo)/2;
        if(nums[mid] > nums[hi]){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    return nums[lo];
}
    int findMin(vector<int>& nums) {
        return bs(nums);
    }
};
