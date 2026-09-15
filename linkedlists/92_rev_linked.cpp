#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* beforeL = nullptr;
        ListNode* l = nullptr;
        ListNode* r = nullptr;
        ListNode* curr = head;
        int iter = 1;
        while(iter <= right){
            if(iter == left - 1)
                beforeL = curr;
            if(iter == left)
                l = curr;
            if(iter == right)
                r = curr;
            iter++;
            curr = curr -> next;
        }
        // store the value after r
        ListNode* afterR = r -> next;
        curr = l -> next;
        ListNode* prev = l;
        ListNode* n = nullptr;
        while(curr != afterR){
            n = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = n;
        }
        if(beforeL != nullptr)
            beforeL -> next = r;
        l -> next = afterR;
        if(left == 1)
            return r;
        return head;
    }
};