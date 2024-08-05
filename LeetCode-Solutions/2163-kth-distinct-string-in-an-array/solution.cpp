auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        for(string s : arr){ mp[s]++; }
        for(string s : arr){
          if(mp[s] == 1) --k;
          if(k == 0) return s;
        }
        return "";
    }
};
