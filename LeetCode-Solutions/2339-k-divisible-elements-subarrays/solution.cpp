class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        //unordered_set<vector<int>>st;
        int count = 0;
        //cout << count << '\n';
        vector<vector<int>> A;
        set<vector<int>>st;
        for(int i = 0; i<n; ++i){
            vector<int>tmp;
            int temp = 0;
            for(int j = i; j<n; ++j){
                if(nums[j] % p == 0) 
                    {temp++;}
                tmp.push_back(nums[j]);
                if(temp>k)break;
                st.insert(tmp);
                }
            }
            return st.size();
        }
};
