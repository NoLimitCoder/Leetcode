class Solution {
public:
    int maxCount(vector<int>& A, int n, int maxSum) {
        //unordered_set<int>mp(A.begin(),A.end());
        vector<int> mp(10001,0); for(int i : A) mp[i] = 1;
        int sum = 0,cnt = 0;
        for(int i = 1; i<=n; ++i){
            if(!mp[i]){
            //if(mp.find(i) == mp.end()){
                if(sum+i <= maxSum) {sum += i; cnt++;}
                else {break;}
            }
        }
        return cnt;
    }
};
