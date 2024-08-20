// Remove Nth Node from Linked List (from back of LL)
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        // Move the fastp pointer N nodes ahead
        for(int i=0; i<n; i++){
            fast= fast-> next;
        }

        // If fastp becomes NULL, the Nth node from the end is the head
        if(fast==NULL){
            return head->next;
        }

        // Move both pointers until fast pointer reaches the end
        // When the fast pointer reaches the last node, i.e., the L-th node, the slow is guaranteed to be at the (L-N)-th node, where L is the total length of the linked list.
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Delete the Nth node from the end
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};
