// Detect loop/cycle in a linked list
// https://leetcode.com/problems/linked-list-cycle/
// https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/

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
    bool hasCycle(ListNode *head) {
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
            return true;  // Loop detected
        }
    }

    // If fast reaches the end of the list, there is no loop
    return false;
    }
};
