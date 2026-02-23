// Last updated: 2/23/2026, 6:57:35 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    //オーバーフロー対策として、筆算を実際にコードでやる
    //前から計算を精査していく
    //繰り上がりがあるのなら、carryという変数を使う
    //値がない(NULL)のなら0にする

    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    if (!dummyHead) return (free(dummyHead), NULL);
    
    dummyHead->val = 0;
    dummyHead->next = NULL;

    struct ListNode* curr = dummyHead;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry + ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0);
        carry = sum/10;

        curr->next = malloc(sizeof(*curr->next));
        if (!curr->next) return (free(dummyHead), NULL);

        curr->next->val = sum%10;
        curr->next->next = NULL;
        curr = curr->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    struct ListNode* result = dummyHead->next;
    free(dummyHead);
    return(result);
}