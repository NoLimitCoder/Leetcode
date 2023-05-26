class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i = 0, j = numbers.size()-1;
        while(i<j){
            int sum = numbers[i] + numbers[j];
            if(sum < target){++i;}
            else if(sum > target){--j;}
            else{
                ans = {i+1,j+1}; break;
            }
        }
        return ans;
    }
};
