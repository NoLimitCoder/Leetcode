class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i = 0; i<nums.size(); ++i){
            mp[nums[i]]++;
        }
        multimap<int,int> ans;
        for(auto it : mp){
            ans.insert({ it.second, it.first });
        }
        vector<int> res;
        for(auto it = ans.rbegin(); it != ans.rend(); ++it){
            if(k == 0) break;
            res.push_back(it->second); k--;
        }
        return res;
    }
};
