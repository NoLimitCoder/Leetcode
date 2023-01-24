class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] answer = new int[2];
        int index = 0;
        int index2 = 0;

        while(index != nums.length){
            int diff = target - nums[index];
            for(int i = index+1; i < nums.length; i++){
                if(nums[i] == diff){
                    index2 = i;
                    break;
                }
            }
            if(index2 != 0){
                break;
            } else {
                index++;
            }
        }

        if(index2 > index){
            answer[0] = index;
            answer[1] = index2;
            return answer;
        }

        int[] noanswer = new int[0];
        return noanswer;
    }
}
