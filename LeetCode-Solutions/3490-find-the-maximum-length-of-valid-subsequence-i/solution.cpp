class Solution {
public:
    int maximumLength(vector<int>& A) {
        //1 force even
        //2 force odd
        int n = A.size();
        int even = 0, odd = 0;
        for(int i = 0; i<n; ++i){
            if(A[i]&1)odd++;
            else even++;
        }
        int ans = 0;
        bool flag = 0;
        int count = 0;
        for(int i = 0; i<A.size(); ++i){
            if(flag) { if(A[i]&1)  {count++; flag = !flag;} }
            else{ if(A[i]%2 == 0 ) {count++; flag = !flag;} }
        }
        ans = max(ans,count);
        flag = 0;
        count = 0;
        for(int i = 0; i<A.size(); ++i){
            if(!flag) { if(A[i]&1)  {count++; flag = !flag;} }
            else{  if(A[i]%2 == 0 ) {count++; flag = !flag;} }
            
        }
        ans = max(ans,count);
     return max({even, odd, ans});
    }
};
