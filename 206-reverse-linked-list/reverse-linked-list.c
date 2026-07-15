/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *new = NULL;
    struct ListNode *temp = head;
    struct ListNode *old = head->next;
    
    while (old != NULL) {
        temp->next = new;
        new = temp;
        temp = old;
        old = old->next;
    }
    temp->next = new;
    new = temp;
    //old->next = temp;
    return new;
}