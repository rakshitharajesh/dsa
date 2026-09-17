#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* kthNode(ListNode* curr, int k){
        while(curr != nullptr && k != 1){
            curr = curr -> next;
            k--;
        }
        return curr;
    }

    void reverse(ListNode* head, ListNode* tail){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* afterTail = tail -> next;
        while(curr != afterTail){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevHead = nullptr;
        ListNode* curr = head;
        ListNode* newHead = nullptr;
        while(true){
            ListNode* kth = kthNode(curr, k);
            // fewer than k nodes remain
            if(kth == nullptr){
                prevHead -> next = curr;
                break;
            }
            ListNode* afterK = kth -> next;
            reverse(curr, kth);
            // if the previous head is declared, connect 
            if(prevHead != nullptr){
                prevHead -> next = kth;
            }
            prevHead = curr;
            curr = afterK;
            // if the head is not reversed yet
            if(newHead == nullptr)
                newHead = kth;
        }
        return newHead;
    }
};