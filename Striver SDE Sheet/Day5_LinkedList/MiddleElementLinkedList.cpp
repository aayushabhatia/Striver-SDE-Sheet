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
        // tortoise and hare algo
        ListNode* slow =  head;
        ListNode* fast = head; // initialising both of them with head
        while(fast!= NULL && fast->next != NULL){
            slow = slow->next; // moving 1 step at a time
            fast = fast->next->next; //moving two steps at a time
        }
        return slow; // by the time fast reaches last node or NULL, slow will be at middle position
        
    }
};
