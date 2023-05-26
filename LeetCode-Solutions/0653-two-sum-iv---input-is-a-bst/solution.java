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
    boolean ans;
    HashSet<Integer> st;
    int K;
    void DFS(TreeNode root){
        if(root == null) return;
        if(st.contains(K-root.val))ans = true;
        st.add(root.val);
        DFS(root.left);DFS(root.right);
    }

    public boolean findTarget(TreeNode root, int k) {
        st = new HashSet<>();
        ans = false;
        K = k;
        DFS(root);
        return ans;
    }
}
