#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Create a dummy head to simplify list construction
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* current = &dummy;
    int carry = 0;

    // Continue as long as there are nodes in either list or a carry remains
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        // Allocate memory for the new node
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = digit;
        newNode->next = NULL;

        // Attach the new node to the result list
        current->next = newNode;
        current = current->next;
    }

    return dummy.next;
}
