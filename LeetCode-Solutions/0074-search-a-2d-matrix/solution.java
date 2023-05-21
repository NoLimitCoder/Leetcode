class Solution {
    int N,M,Target;
    public boolean can(int mid, int[][] matrix){
         int x = mid/M; int y = mid%M;
        return matrix[x][y] >= Target;
    }

    public boolean BS(int target, int[][] matrix){
        int hi,lo,mid;
        lo = 0; hi = (M*N) -1;
        while(lo<=hi){
            mid = (hi+lo)/2;
            System.out.printf("\nhi: %d\n",hi);
            System.out.printf("lo: %d\n",lo);
            System.out.printf("mid: %d\n",mid);
            if(can(mid, matrix)){
                int x = mid/M; int y = mid%M;
                if(matrix[x][y] == target) return true;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            } 
        }
        return false;
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        N = matrix.length;
        M = matrix[0].length;
        Target = target;
        if(M==1 && N ==1 ) return matrix[0][0] == target;
        System.out.printf("%d %d\n",N,M);
        for(int i = 0; i<N*M; ++i){
            int x, y;
            x = i/M; y = i%M;
            System.out.printf("%d ",matrix[x][y]);
        }
        return BS(target,matrix);
        
    }
}
























//
