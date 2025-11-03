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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(inorder.length!=postorder.length) return null;
        HashMap<Integer,Integer> mpp = new HashMap<>();
        for(int i=0;i<inorder.length;i++){
            mpp.put(inorder[i],i);
        }
        int iend = inorder.length;
        int pend = postorder.length;
        return build(0,iend-1,inorder,0,pend-1,postorder,mpp);
    }
    
    TreeNode build(int istart,int iend,int[] inorder,int pstart,int pend,int[] postorder,HashMap<Integer,Integer> mpp){
        if(istart>iend || pstart>pend) return null;
        TreeNode root = new TreeNode(postorder[pend]);
        int inroot = mpp.get(root.val);
        int els=inroot-istart;
        root.left =build(istart,inroot-1,inorder,pstart,pstart+els-1,postorder,mpp);
        root.right=build(inroot+1,iend,inorder,pstart+els,pend-1,postorder,mpp);
        return root;
    }
}