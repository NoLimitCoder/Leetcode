class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long ans = 0;
        for(long long i = 0; i<k; ++i){
            if(happiness[i] - i < 0) break;
            ans += happiness[i];
            ans -= i;
        }
        return ans;
    }
};
