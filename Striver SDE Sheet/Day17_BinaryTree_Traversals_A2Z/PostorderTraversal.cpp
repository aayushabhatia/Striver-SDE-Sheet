// https://takeuforward.org/data-structure/post-order-traversal-of-binary-tree/
// https://leetcode.com/problems/binary-tree-postorder-traversal/

// 1. Recursive
class Solution {
public:
    void postorder(TreeNode* root, vector<int> &arr){
        if(root==NULL){
            return;
        }
        postorder(root->left, arr);
        postorder(root->right, arr);
        arr.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        postorder(root, arr);
        return arr;
    }
};


// 2. Iterative - using 2 stacks
// https://www.youtube.com/watch?v=2YBhNLodD8Q&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=12

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        vector<int> postorder_traversal;
        if(root==NULL){
            return postorder_traversal;
        }
        s1.push(root);
        while(s1.size()>0){
            root = s1.top();
            s1.pop();
            s2.push(root);
            if(root->left!=NULL){
                s1.push(root->left);
            }
            if(root->right!=NULL){
                s1.push(root->right);
            }
        }
        while(s2.size()>0){
            postorder_traversal.push_back(s2.top()->val);
            s2.pop();
        }
        return postorder_traversal;
    }
};
