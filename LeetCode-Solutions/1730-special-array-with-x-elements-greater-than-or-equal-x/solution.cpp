class Solution {
public:
//brute force

    bool check(vector<int>& nums, int k){
        int count = 0;
        for(auto x : nums){
            if(x >= k) count++;
        }
        return count == k;
    }
    int specialArray(vector<int>& nums) {
        for(int i = 1000; i>=0; --i){
            if(check(nums,i)) return i;
        }

        return -1;
    }
};
