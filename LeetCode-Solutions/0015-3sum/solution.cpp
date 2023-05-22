#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int i, j, sum, k;
        sort(nums.begin(),nums.end());
        //set<multiset<int>> st;
        vector<vector<int>>ans;
        for(int k = 0; k<n; ++k){
             if (k > 0 && nums[k] == nums[k - 1]) continue;
            i = k+1, j = n-1;
            while(i < j){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){j--;}
                else if(sum < 0){i++;}
                else if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(i < j && nums[i] == nums[i+1] ){ i++;}
                    while(i < j && nums[j] == nums[j-1] ){ j--;}
                    i++;
                    j--;
                }
            }
        }
        return ans;


    }
};
