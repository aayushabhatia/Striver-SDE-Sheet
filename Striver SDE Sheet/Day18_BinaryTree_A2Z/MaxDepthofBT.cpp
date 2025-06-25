// https://takeuforward.org/data-structure/maximum-depth-of-a-binary-tree/
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

// Level Order Traversal Method
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth=0;
        if(root==NULL){
            return depth;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int size= q.size();
            depth++;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
        }
        return depth;
    }
};

// Recursive Method
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1+max(left, right);
    }
};
