// https://leetcode.com/problems/symmetric-tree/description/?envType=problem-list-v2&envId=eeudwo2i

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
private:
    bool isMirror(TreeNode* n1, TreeNode* n2){
        // 2 base cases
        // when both are null , means we reached end of tree
        if(n1 == NULL && n2 == NULL){
            return true;
        }
        // if one of them is null then tree is not symmetric
        if(n1 == NULL || n2 == NULL){
            return false;
        }
        return n1->val == n2->val && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    }
};
