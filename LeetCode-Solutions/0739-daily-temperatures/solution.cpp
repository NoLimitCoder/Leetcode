#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
class Solution {
public:

vector<int> solve1(vector<int>& A){

        int n = A.size();
        vector<int>ans(n);
        ans[n-1] = 0;
        stack<pair<int,int>>stk;
        for(int i = 0; i<n-1; ++i){
            if(A[i+1] > A[i]){
                ans[i] = 1;
                while(!stk.empty()){
                    pair<int,int> tmp = stk.top();
                    if(A[i+1] > tmp.first){
                        stk.pop();
                        ans[tmp.second] = (i+1) - tmp.second;
                    }
                    else{break;}
                }
            }
            else{
                stk.push({A[i],i});
            }
        }
        while(!stk.empty()){
            pair<int,int> tmp = stk.top();
            ans[tmp.second] = 0;
            stk.pop();
        }
        return ans;
}

vector<int> solve2(vector<int>& A){
    //next greater element problem -> Sol: start from end and use stack to keep track of next greater element at each index
    int n = A.size();
    vector<int>nge(n,0);
    stack<int>stk;
    for(int i = n-1; i>=0; --i){
        while(!stk.empty() && A[i] >= A[stk.top()]) {stk.pop();}
        nge[i] = stk.empty()? 0 : stk.top() - i;
        stk.push(i);
    }

    return nge;
}


    vector<int> dailyTemperatures(vector<int>& A) {
        ios();
        //return solve1(A);
        return solve2(A);
    }
};
