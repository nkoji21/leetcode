#include <stdio.h>

/**
それぞれのリストのvalを見て、小さい方を先に入れて大きい方を後に入れる
list1の方が小さいならば、現在のノードのnextをlist1にして、
list1を1つ進める

そうじゃなくて、list2の方が小さいなら、現在のノードをlist2にして、
list2を1つ進める

現在のノードの位置を最後に進める
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  struct ListNode dummy = {0, NULL};
  struct ListNode* cur = &dummy;

  while (list1 != NULL && list2 != NULL) {
    if (list1->val <= list2->val) {
      cur->next = list1;
      list1 = list1->next;
    } else {
      cur->next = list2;
      list2 = list2->next;
    }

    cur = cur->next;
  }

  cur->next = (list1 != NULL) ? list1 : list2;

  return (dummy.next);
}

int main(void) {
  printf("Hello world!");
  return 0;
}
