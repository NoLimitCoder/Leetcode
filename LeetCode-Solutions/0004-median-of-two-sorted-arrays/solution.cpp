class Solution {
public:

    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int i = 0, j = 0;
        vector<int> ans;
        while(i < nums1.size() && j < nums2.size() ){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                ans.push_back(nums2[j]);
                j++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;  
            }
        }
        while(i < nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans = merge(nums1,nums2);
        int n = ans.size();
        if(n & 1){
        return (double) (ans[n/2]);
        }
            return (double) (((ans[(n/2)-1])+(ans[n/2]))/2.0);
    }
};
