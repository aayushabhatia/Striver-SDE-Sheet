// https://takeuforward.org/data-structure/inorder-traversal-of-binary-tree/
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

// Recursive
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &arr){
        if(root==NULL){
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return arr;
    }
};


// Iterative
// https://www.youtube.com/watch?v=lxTGsVXjwvM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=11

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* node = root;
        vector<int> inorder_traversal;
        while(true){
            if(node!=NULL){
                s.push(node);
                node = node->left;
            }
            else{
                if(s.size()==0){
                    break;
                }
                node=s.top();
                s.pop();
                inorder_traversal.push_back(node->val);
                node= node->right;
            }
        }
        return inorder_traversal;
    }
};
