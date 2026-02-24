class Solution {
public:
    void level(TreeNode* root, string curr, int &sum) {
        if (root == NULL) return;
        //for the current root
        curr+=to_string(root->val);
        
        if (root->left==NULL && root->right==NULL) {
            //yeh binary to decimal conversion ke liye hai
            sum+=stoi(curr, 0, 2);
            return;
        }
        level(root->left,curr,sum);
        level(root->right,curr,sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        level(root,"",sum);
        return sum;
    }
};