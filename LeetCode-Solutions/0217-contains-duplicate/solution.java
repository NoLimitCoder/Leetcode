class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i = 0; i<nums.length; ++i){
            if(mp.containsKey(nums[i])){
                mp.replace(nums[i],mp.get(nums[i])+1);
            }
            else{
                mp.put(nums[i],1);
            }
        }
        for(Integer i : mp.values()){
            if(i > 1) return true;
        }
        return false;
    }
}
