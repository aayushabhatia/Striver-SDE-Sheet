// https://takeuforward.org/data-structure/check-if-the-binary-tree-is-balanced-binary-tree/
// https://leetcode.com/problems/balanced-binary-tree/

// using height of tree concept
class Solution {
public:
    int height(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        if(abs(leftheight - rightheight) <=1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
};
