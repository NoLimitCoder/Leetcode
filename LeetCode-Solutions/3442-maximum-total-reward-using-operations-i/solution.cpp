
typedef long long ll;
class Solution {
public:

    
    int maxTotalReward(vector<int>& A) {
        //sum = 0;
        //n = [1,6,4,3,2]
        //dp[x] = is possible
        map<int,int> mp; 
        int ans = 0; mp[0] = 1;
        sort(A.begin(), A.end());
        for(int i = 0; i<(int)A.size(); ++i){
            for(auto it : mp){
                if(it.first < A[i]) {
                    mp[it.first + A[i]] = 1;
                    ans = max(ans, it.first + A[i]);
                }
                else break;
            }
        }
        return ans;
    }
};
