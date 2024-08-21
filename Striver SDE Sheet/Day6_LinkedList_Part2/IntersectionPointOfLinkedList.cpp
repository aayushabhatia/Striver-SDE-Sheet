// Find Intersection Point of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/
// https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if( headA == NULL || headB == NULL)
            return NULL;
        // initialising two linked lists with two dummy pointers
        ListNode* a= headA;
        ListNode* b= headB;
        while(a != b) {
            // traversing dummy nodes in each linked list till one of them reaches null pt that is end and then that pointer is intialised with head node of another linked list
            a = a == NULL? headB:a->next;
            b = b == NULL? headA:b->next;
        }
        return a;
    }
};
