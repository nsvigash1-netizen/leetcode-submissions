/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head->next == NULL)
        return NULL;

    struct ListNode* fastPtr = head;
    struct ListNode* slowPtr = head;
    struct ListNode* prevPtr = NULL;
    
    while (fastPtr != NULL && fastPtr->next != NULL) {
        prevPtr = slowPtr;        
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    prevPtr->next = slowPtr->next;
    return head;
}