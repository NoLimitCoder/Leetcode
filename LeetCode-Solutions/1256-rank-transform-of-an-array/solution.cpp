class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> b = arr;
        sort(b.begin(), b.end());
        unordered_map<int,int> mp;
        int i = 1;
        for(int x : b){
            if(!mp[x]) mp[x] = i++;
        }
        
        for(int i = 0; i<arr.size(); ++i){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};
