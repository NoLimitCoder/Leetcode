class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int mp[1001]; vector<int> ans;
        for(int i : arr1)
            { mp[i]++; }
        for(int i : arr2)
            { while(mp[i] > 0){ans.push_back(i); mp[i]--;} }
        for(int i = 0; i<=1000; ++i)
            { while(mp[i] > 0){ans.push_back(i);mp[i]--;} }
        return ans;
    }
};
