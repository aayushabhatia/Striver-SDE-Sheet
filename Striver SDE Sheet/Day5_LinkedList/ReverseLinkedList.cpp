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

// DSA Udemy solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* c = head;
        ListNode* p = NULL;
        ListNode* N;
        while(c != NULL){
            N = c-> next;
            c -> next = p;
            p = c;
            c = N;
        }
        head = p;
        return head;
    }
};
