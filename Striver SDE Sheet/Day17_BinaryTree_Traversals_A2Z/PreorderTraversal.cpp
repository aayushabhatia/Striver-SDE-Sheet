// https://takeuforward.org/data-structure/preorder-traversal-of-binary-tree/
// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Recursive
class Solution {
public:
    void preorder(TreeNode* root, vector<int> &arr) {
        if(root==NULL){
            return;
        }
        arr.push_back(root->val);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        preorder(root, arr);
        return arr;
    }
};


// Iterative
// https://www.youtube.com/watch?v=Bfqd8BsPVuw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=10

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder_traversal;
        if(root==NULL){
            return preorder_traversal;
        }

        stack<TreeNode*> s;
        s.push(root);
        while(s.size()>0){
            root=s.top();
            s.pop();
            preorder_traversal.push_back(root->val);
            if(root->right!=NULL){
                s.push(root->right);
            }
            if(root->left!=NULL){
                s.push(root->left);
            }
        }
        return preorder_traversal;
    }
};
