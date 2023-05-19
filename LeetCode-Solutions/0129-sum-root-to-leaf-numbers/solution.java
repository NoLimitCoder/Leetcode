/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public ArrayList<String> A;

    public void dfs(TreeNode root, String currentNumber){
        if(root == null) return;
        
        if(root.left == null && root.right == null){
            //System.out.printf("%d ",root.val);
            currentNumber += Integer.toString(root.val);
            A.add(currentNumber);
            return;
        }
        currentNumber += Integer.toString(root.val);
        dfs(root.left,currentNumber); dfs(root.right,currentNumber);
    }


    public int sumNumbers(TreeNode root) {
        A = new ArrayList<String>();
        dfs(root,"");
        int sum = 0;
       // System.out.printf("\n");
        for(int i = 0; i<A.size(); ++i){
            //System.out.printf("%s ",A.get(i));
            sum += Integer.parseInt(A.get(i));
        }
        return sum;
    }
}






























//
