/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
  bool ismirror(struct TreeNode *root1,struct TreeNode* root2)
 {    
     if(root1==NULL && root2==NULL)return true;
     if(root1==NULL || root2==NULL || root1->val!=root2->val)return false;
      
        return (ismirror(root1->left,root2->right) && ismirror(root1->right,root2->left));
     
      return false;
    
}
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)return true;

    return ismirror(root->left,root->right);
}    
