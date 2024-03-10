    
struct CustomCompare {
    bool operator()(const string& s1, const string& s2) const {
        if (s1.length() != s2.length()) {
            return s1.length() < s2.length();
        }
        // If lengths are equal, compare lexicographically
        return s1 < s2;
    }
};

bool compare(const string& s1, const string& s2){
            if (s1.length() != s2.length()) {
            return s1.length() < s2.length();
        }
        // If lengths are equal, compare lexicographically
        return s1 < s2;
    
}

class Solution {
public:


set<string,CustomCompare> generateSubstrings(const string& s) {
    set<string,CustomCompare> substrings;
    int n = s.length();
    for (int len = 1; len <= n; ++len) {
        for (int start = 0; start <= n - len; ++start) {
            substrings.insert(s.substr(start, len));
        }
    }
    return substrings;
}
    

    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> ans;
        //generate all substrings for each element
        map<int,set<string,CustomCompare>>mp;
        for(int i = 0; i<n; ++i){
            set<string,CustomCompare> iSubstrings = generateSubstrings(arr[i]);
            mp[i] = iSubstrings;
        }
        //go through each substring in set for current index, and check against all sets of all indices, if not present add to solution
        for(int i = 0; i<n; ++i){
            //each element of set 
            for(auto it : mp[i]){
                //against everything else
                bool flag = true;
                for(int j = 0; j<n; ++j){
                    if(i==j)continue;
                    if(mp[j].find(it) != mp[j].end()){flag = false;}
                }
               if(flag){ans.push_back(it); break;}
            }
            if(ans.size()==i){ans.push_back("");}
        }
        return ans;
    }
};
