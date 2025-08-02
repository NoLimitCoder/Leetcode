const int INF = 2e9;
#define rep(i,n) for(int i = 0; i<n; ++i)
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int ans = INF;
        rep(i,n) rep(j,m){
            int a = landStartTime[i] + landDuration[i];
            int k = max(a, waterStartTime[j]) + waterDuration[j];
            int b = waterStartTime[j] + waterDuration[j];
            int l = max(b,landStartTime[i]) + landDuration[i];
            ans = min({ans,k,l});
        }
        return ans;
    }
};
