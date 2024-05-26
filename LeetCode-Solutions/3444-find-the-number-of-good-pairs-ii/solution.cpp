#pragma GCC optimize("O3,unroll-loops")
typedef long long ll;
class Solution 
{
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<ll,ll>habibi;
        for(auto num : nums2){
            habibi[num*k]++;
        }
        ll res = 0;
        for(auto num : nums1){
            for(int i = 1; i<=sqrt(num); ++i){
                if(num % i == 0){
                    res += habibi[i];
                    if(i*i != num){res += habibi[num/i];}
                }
            }
        }
        return res;
    }
};
