class Solution {
public:
    long long maximumValueSum(vector<int>& A, int k, vector<vector<int>>& edges) {
        multiset<long long> XoredVals; 
        long long ans = 0;
        for(int i = 0; i < A.size(); ++i){
            XoredVals.insert((A[i] ^ k) - A[i]); 
            ans += A[i];
        }
        auto it = XoredVals.rbegin(); 
        bool flag = 0;
        for(; it != XoredVals.rend(); ++it){
            if(*it >= 0) {ans += *it;}
            else           {break;}
            flag = !flag;
        }
        //if the number of nodes is odd
        if(flag){
            //if we reached the end, we have to remove the smallest element
            if(it == XoredVals.rend())
                {return ans - *XoredVals.begin();}
            //if we did not reach the end, we have to return the max of taking the next element or removing the previous one
            else
                {return max( ans + *it, ans - *(--it) );}
        }
        //if the number of nodes is even then we just return our current answer
        return ans;
    }
};
