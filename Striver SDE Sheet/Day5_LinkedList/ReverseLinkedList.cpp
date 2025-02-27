// Reverse a Linked List
// https://leetcode.com/problems/reverse-linked-list/
// https://takeuforward.org/data-structure/reverse-a-linked-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// striver soln
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head; 
        ListNode* prev = NULL;  
        while(temp != NULL){  
            ListNode* front = temp->next; 
            temp->next = prev;  
            prev = temp; 
            temp = front; 
        }
        return prev;  
    }
};

