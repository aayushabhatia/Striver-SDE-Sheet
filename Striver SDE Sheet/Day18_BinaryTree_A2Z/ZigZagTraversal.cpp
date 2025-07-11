// https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree/
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true; // treu for L to R, false for R to L
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size); // to store the values of nodes at the current level
            // traversing nodes at current level
            for(int i=0; i< size; i++){
                TreeNode* node = q.front();
                q.pop();
                // to find index to insert the node's value based on the traversal direction
                int index = (flag) ? i : (size-i-1); // i for from L to Rie from start and (size-i-1) for R to L ie from end
                row[index] =  node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            // to switch traversal dirn for next level
            flag = !flag;
            result.push_back(row);
        }
        return result;
    }
};
