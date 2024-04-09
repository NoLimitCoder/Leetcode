#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
class Solution {
public:
int INF = 2e9;


    int maxSubArray(vector<int>& nums) {
        fast_io();
        //Kadane's Algo
        int mx = -INF;
        int sum = 0;
        for(int i = 0; i<nums.size(); ++i){
            if(sum < 0) sum = 0; 
            sum += nums[i];
            mx = max(mx,sum);
        }
        return mx;
    }
};
