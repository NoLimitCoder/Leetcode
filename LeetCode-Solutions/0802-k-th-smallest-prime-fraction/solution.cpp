class Solution {
public:

struct frac{
    double val;
    int num, denum;
};

    vector<frac> genFractions(vector<int>& arr){
        vector<frac> ans;
        int n = arr.size();
        for(int i = 0; i<n; ++i){
            for(int j = i+1; j<n; ++j){
                ans.push_back(  {(arr[i]+0.0) / (arr[j]+0.0), arr[i], arr[j]}   );
            }
        }
        sort(ans.begin(), ans.end(), [](const frac &a, const frac &b){
            return a.val < b.val;
        });
        return ans;
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<frac> ans = genFractions(arr);
        //for(int i = 0; i<ans.size(); ++i){
         //   cout << i << ": " << ans[i].val << ' ' << ans[i].num << ' ' << ans[i].denum << '\n';
       // }
        return {ans[k-1].num,ans[k-1].denum};
    }
};
