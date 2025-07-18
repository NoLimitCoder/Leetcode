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
    int sum;
    public void dfs(TreeNode root, Integer currentNumber){
        if(root == null) return;
        if(root.left == null && root.right == null){
            currentNumber*=10; currentNumber += root.val;
            sum += currentNumber;
            return;
        }
        currentNumber*=10; currentNumber += root.val;
        dfs(root.left,currentNumber); dfs(root.right,currentNumber);
    }
    public int sumNumbers(TreeNode root) {
        sum = 0;
        dfs(root,0);
        return sum;
    }
}






























//
