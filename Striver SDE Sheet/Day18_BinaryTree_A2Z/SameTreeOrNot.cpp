// https://takeuforward.org/data-structure/check-if-two-trees-are-identical/
// https://leetcode.com/problems/same-tree/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return (p==q);
        }
        // preorder traversal (root, left, right) done, otherwise any traversal can be done to check
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
