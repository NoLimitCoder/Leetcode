class Solution {
public:
    const int INF = 2e9;
    int findMaxK(vector<int>& nums) {
        int mx = -1;
        sort(nums.begin(), nums.end());
        for(int num : nums){
            if(binary_search(nums.begin(), nums.end(), -num)){mx = max(mx, num);}
        }
        return mx;
    }
};
