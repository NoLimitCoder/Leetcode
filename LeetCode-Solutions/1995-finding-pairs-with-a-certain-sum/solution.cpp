class FindSumPairs {
public:
    unordered_map<int,int> mp;
    vector<int> n1, n2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1; n2 = nums2; mp.clear();
        for(int i : nums2) ++mp[i];
    }
    
    void add(int i, int val) {
        int num = n2[i];
        mp[n2[i]]--;
        n2[i] += val;
        mp[n2[i]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i : n1){ if(tot-i >= 0) ans += mp[tot-i]; }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
