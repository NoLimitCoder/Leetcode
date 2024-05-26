class Solution {
    private final int MOD = 1000000007;
    private long getMaxSumNonAdjacent(int[] arr) {
        long incl = Math.max(arr[0], 0);
        long excl = 0;
        
        for (int i = 1; i < arr.length; i++) {
            long new_excl = Math.max(incl, excl);
            incl = excl + arr[i];
            excl = new_excl;
        }
        return Math.max(incl, excl);
    }

    public int maximumSumSubsequence(int[] nums, int[][] queries) {
        long sum = 0;
        for (int[] query : queries) {
            int pos = query[0];
            int val = query[1];
            nums[pos] = val;
            sum = (sum + getMaxSumNonAdjacent(nums)) % MOD;
        }
        return (int) sum;
    }
}
