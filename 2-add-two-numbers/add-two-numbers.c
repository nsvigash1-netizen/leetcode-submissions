/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    
    struct ListNode *result = NULL;    
    struct ListNode *prev = NULL;
    int carry = 0;
    
    while(l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;
        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;       
        }
        carry = sum / 10;

        struct ListNode *current = malloc(sizeof(*current));
        current->val = sum % 10;
        current->next = NULL;
        
        // prev is NULL only in the first iteration
        if (prev == NULL) {
            result = current;
        } else {
            prev->next = current;
        }

        prev = current;
    }
    return result;       
}