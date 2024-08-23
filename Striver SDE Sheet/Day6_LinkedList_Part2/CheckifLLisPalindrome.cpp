// Check is given Linked List is a palindrome or not
// https://leetcode.com/problems/palindrome-linked-list/
// https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/

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
    bool isPalindrome(ListNode* head) {
    // Create an empty stack to store values
    stack<int> st;
    // Initialize a temporary pointer to the head of the linked list
    ListNode* temp = head;

    // Traverse the linked list and push values onto the stack
    while (temp != NULL) {
        // Push the data from the current node onto the stack
        st.push(temp->val); 
         // Move to the next node
        temp = temp->next;  
    }

    // Reset the temporary pointer back to the head of the linked list
    temp = head;

    // Compare values by popping from the stack and checking against linked list nodes
    while (temp != NULL) {
        if (temp->val != st.top()) {
            // If values don't match, it's not a palindrome
            return false; 
        }
        // Pop the value from the stack
        st.pop();         
        // Move to the next node in the linked list
        temp = temp->next; 
    }
     // If all values match, it's a palindrome
    return true;
    }
};
