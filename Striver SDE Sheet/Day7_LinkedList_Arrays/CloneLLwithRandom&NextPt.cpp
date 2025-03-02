// Clone Linked List with Random and Next Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/description/
// https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/

// A deep copy of the linked list has to be created while maintaining all ‘next’ and ‘random’ pointers to the appropriate new nodes. Additional memory allocation is done while creating a duplicate set of nodes and managing their pointer relationships.

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    void insertCopyInBetween(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
    }

    void connectRandomPointers(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copyNode = temp->next;
            if(temp->random){
                copyNode->random = temp->random->next;
            }
            else{
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }
    }

    Node* connectNextPointers(Node* head){
        Node* temp = head;
        Node* dNode = new Node(-1);
        Node* res = dNode;
        while(temp!=NULL){
            // Creating a new List by pointing to copied nodes
            res->next = temp->next;
            res = res->next;
            // Disconnect and revert back to the initial state of the original linked list
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dNode->next;
    }
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return connectNextPointers(head);
    }
};
