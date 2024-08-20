// Delete a given node in LinkedList 
// https://leetcode.com/problems/delete-node-in-a-linked-list/
// https://takeuforward.org/data-structure/delete-given-node-in-a-linked-list-o1-approach/

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
    void deleteNode(ListNode* node) {
        node->val= node->next->val;
        node->next= node->next->next;
    }
};
