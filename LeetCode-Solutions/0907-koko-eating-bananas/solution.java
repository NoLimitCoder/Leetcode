class Solution {

    public boolean can(int k, int[] piles, int h){
        int ans = 0;
        for(int i = 0; i< piles.length; ++i){
            ans += Math.ceil((piles[i]+0.0) / (k+0.0));
        }
        //System.out.printf("k: %d, ans: %d\n",k,ans);
        return ans <=h;
    }

    public int BS(int[] piles, int h){
        int hi, lo, mid;
        hi = 1000000000; lo = 0; mid = -1;
        int ans = -1;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(can(mid,piles,h)){
                hi = mid-1;
                ans = mid;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }

    public int minEatingSpeed(int[] piles, int h) {
        return BS(piles,h);
    }
}
