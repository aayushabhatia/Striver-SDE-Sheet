struct Node {
    int data;        
    Node* left;      
    Node* right;      

    // Method to initialize the node with a value
    Node(int val) {
        data = val;   
        left = right = NULL;  
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
}
