class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size(); vector<pair<int,int>>v; vector<int> ans;
        for(int i = 0; i<n; ++i){ 
            v.push_back({nums[i],i}); 
        }
        sort(v.rbegin(), v.rend());
        sort(v.begin(), v.begin() + k, [](auto &a, auto &b){
            return a.second < b.second;
        });
        for(int i = 0; i<k; ++i){ans.push_back(v[i].first);}
        return ans;
    }
};
