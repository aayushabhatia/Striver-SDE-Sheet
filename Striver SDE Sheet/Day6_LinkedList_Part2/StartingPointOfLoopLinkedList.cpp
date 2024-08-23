// Starting Node of Loop in Linked List
// https://leetcode.com/problems/linked-list-cycle-ii/
// https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/

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
    ListNode *detectCycle(ListNode *head) {
        // Initialize two pointers, slow and fast, to the head of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the linked list with the slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next;
        // Move fast two steps
        fast = fast->next->next;

        // Check if slow and fast pointers meet
       if (slow == fast) {
             // Reset the slow pointer to the head of the list
            slow = head; 
            // Find the first node of the loop
            while (slow != fast) {
                // Move slow and fast one step at a time
                slow = slow->next;  
                fast = fast->next;  
                // When slow and fast meet again, it's the first node of the loop
            }
            // Return the first node of the loop
            return slow; 
       }
    }
    // If fast reaches the end of the list, there is no loop
    return NULL;
    }
};
