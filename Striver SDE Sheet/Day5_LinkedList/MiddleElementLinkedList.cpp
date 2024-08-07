// Middle Element of Linked List
// https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
// https://leetcode.com/problems/middle-of-the-linked-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    // Initialize the slow pointer to the head.
    ListNode *slow = head; 
    
     // Initialize the fast pointer to the head.
    ListNode *fast = head; 

    // Traverse the linked list using the Tortoise and Hare algorithm.
    while (fast != NULL && fast->next != NULL) {
        // Move slow one step.
        slow = slow->next; 
         // Move fast two steps.
        fast = fast->next->next; 
    }
     // Return the slow pointer, which is now at the middle node.
    return slow; 
    }
};
