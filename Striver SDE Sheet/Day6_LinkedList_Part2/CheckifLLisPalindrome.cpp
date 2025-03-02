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

// solution 1
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


// solution 2
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* newHead = reverse(slow);  // Fix: Start from 'slow', not 'slow->next'

        // Step 3: Compare both halves
        ListNode* first = head;
        ListNode* second = newHead;
        bool isPalin = true;  // Store the result separately

        while (second != NULL) {
            if (first->val != second->val) {
                isPalin = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        // Step 4: Restore the original list structure
        reverse(newHead);  // Fix: Ensure the list structure is restored

        return isPalin;
    }

};
