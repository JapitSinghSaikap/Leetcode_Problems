/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //first inoder for the tree to get the order for the bst as root is in the middle (aur left mein sarre smaller elements and right mein bdhe elements)
    void inorder(TreeNode* root,vector<int>& arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

    TreeNode* build(TreeNode* root,int l,int r,vector<int>& arr){
        if(l>r) return nullptr;

        int mid = (l+r)/2;

        TreeNode* midd = new TreeNode(arr[mid]);

        midd->left=build(midd,l,mid-1,arr);
        midd->right=build(midd,mid+1,r,arr);

        return midd;

    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        int n=arr.size();
        return build(root,0,n-1,arr);
    }
};

