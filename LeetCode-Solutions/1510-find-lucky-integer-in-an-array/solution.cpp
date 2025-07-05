class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> mp(502);
        for(int i : arr) mp[i]++;
        for(int i = 500; i > 0; --i){
            if(mp[i] == i) return i;
        }
        return -1;
    }
};
