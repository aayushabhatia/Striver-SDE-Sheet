// Flattening of Linked List (having child/bottom node and next node)
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// https://takeuforward.org/data-structure/flattening-a-linked-list/

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};


class Solution {
public:
    // Merge two sorted linked lists
    Node* merge(Node* list1, Node* list2) {
        // Create a dummy node as a placeholder for the result
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        // Merge the lists based on data values
        while (list1 != NULL && list2 != NULL) {
            if (list1->data < list2->data) {
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            } else {
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
        }

        // Connect the remaining elements if any
        if (list1) {
            res->bottom = list1;
        } else {
            res->bottom = list2;
        }

        // The result is the next node after the dummy node
        Node* flattenedList = dummyNode->bottom;
        
        // Free the dummy node
        delete dummyNode;
        
        return flattenedList;
    }

    // Function which returns the root of the flattened linked list.
    Node* flatten(Node* root) {
        // If root is null or there is no next node, return root
        if (root == NULL || root->next == NULL) {
            return root;
        }

        // Recursively flatten the rest of the linked list
        Node* flattenedNext = flatten(root->next);
        
        // Merge the current list with the flattened next list
        root = merge(root, flattenedNext);
        
        // Return the flattened list
        return root;
    }
};
