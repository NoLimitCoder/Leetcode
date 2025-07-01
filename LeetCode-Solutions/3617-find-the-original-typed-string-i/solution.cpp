class Solution {
public:
    int possibleStringCount(string A) {
        int ans = 1;
        vector<int> wds;
        int i = 0, j = 1;
        for(;j<A.size(); ++j){
            if(A[i] == A[j]);
            else {wds.push_back(j-i); i = j;} 
        }
        wds.push_back(j-i);
        for(int i : wds) if(i) ans += i-1;
        return ans;
    }
};
