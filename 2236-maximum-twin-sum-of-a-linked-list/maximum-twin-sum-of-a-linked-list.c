/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    // finding middle of list
    struct ListNode* fastPtr = head;
    struct ListNode* current = head;
    while (fastPtr != NULL && fastPtr->next != NULL) {
        current = current->next;
        fastPtr = fastPtr->next->next;
    }
    // current is head of second half of list
    // Reversing second half of list
    struct ListNode* prev = NULL;
    struct ListNode* nxt = NULL;
    while (current != NULL) {
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    // prev is the head of reversed second half of list
    // finding max twin sum
    int max = 0;
    while (head != NULL && prev != NULL) {
        if (head->val + prev->val > max) {
            max = head->val + prev->val;
        }
        head = head->next;
        prev = prev->next;
    }
    return max;
}