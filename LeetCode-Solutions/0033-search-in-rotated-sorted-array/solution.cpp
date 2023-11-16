class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1, mid = 0;

        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid] == target) return mid;
            //we are in L
            if(nums[mid] > nums[hi]){
                if(target < nums[lo] || target > nums[mid]){
                    //switch to other side
                    lo = mid +1;
                }
                else{
                    //stay on L
                    hi = mid -1;
                }
            }
            //we are in R
            else{
                if(target > nums[hi] || target < nums[mid]){
                    //switch to other side
                    hi = mid -1;
                }
                else{
                    lo = mid + 1;
                }
            }
        }
        return -1;
    }
};
