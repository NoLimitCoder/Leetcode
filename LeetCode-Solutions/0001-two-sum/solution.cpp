#define deb(x) cerr << #x << ": " << x << '\n'
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int i = 0, j = n-1;
        vector<int> ans;
        vector<pair<int,int>> nums2(n);
        for(int idx = 0; idx < n; ++idx){
            nums2[idx] = make_pair(nums[idx], idx);
        }
        sort(nums2.begin(), nums2.end());
        while(i < j){
            int sum = nums2[i].first + nums2[j].first;
            if(sum> target)
                {j--;}
            else if (sum < target)
                {i++;}
            else
                {ans.push_back(nums2[i].second);ans.push_back(nums2[j].second); break;}
        }
        return ans;
    }
};
