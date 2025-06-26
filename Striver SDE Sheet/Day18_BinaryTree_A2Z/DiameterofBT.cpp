// https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
// https://leetcode.com/problems/diameter-of-binary-tree/description/

class Solution {
public:
    int diameter=0;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left= height(root->left);
        int right= height(root->right);
        diameter = max(diameter, left+right); // diameter keeps getting updated
        return 1+max(left, right); // height of current node is returned
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};
