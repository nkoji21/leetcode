#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b) { return a < b ? b : a; }
static inline int min(int a, int b) { return a < b ? a : b; }

// comparison function signature for qsort()
static int cmp(const void* a, const void* b) {
  int x = *(int*)a, y = *(int*)b;
  return (x > y) - (x < y);
}

struct ListNode {
  int val;
  struct ListNode* next;
};

static struct ListNode* makeList(int* arr, int len) {
  struct ListNode dummy = {0, NULL};
  struct ListNode* cur = &dummy;

  for (int i = 0; i < len; i++) {
    struct ListNode* node = malloc(sizeof(struct ListNode));

    node->val = arr[i];
    node->next = NULL;

    cur->next = node;
    cur = cur->next;
  }

  return (dummy.next);
}

static void printList(struct ListNode* head) {
  while (head) {
    printf("%d", head->val);
    if (head->next) printf(" -> ");

    head = head->next;
  }

  printf("\n");
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
まず、nまでリストを進める ahead (前からn+1番目のノードがaheadになる)
behind(リストの最初)をaheadまで進めながら、aheadをNULLじゃなくなるまで進める
すると、aheadがNULLになった時のbehindがn番目になる

[1, 2, 3, 4] n=2
ahead n+1-> dummy -> 1 -> 2 -> 3 -> 4 -> NULLだから、
3になる

behindがdummyスタートで、aheadは3スタートだから
1歩目: behind(1), ahead(4)
2歩目: behind(2), ahead(NULL) になったから、
behind->next を behind->next = behind->next->next にする
*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  struct ListNode dummy = {0, head};
  struct ListNode *ahead = &dummy, *behind = &dummy;

  for (int i = 0; i <= n; i++) ahead = ahead->next;

  while (ahead != NULL) {
    ahead = ahead->next;
    behind = behind->next;
  }

  behind->next = behind->next->next;
  return (dummy.next);
}

int main(void) {
  int arr[] = {1, 2, 3, 4, 5};
  struct ListNode* list = makeList(arr, 5);
  printList(list);

  list = removeNthFromEnd(list, 2);
  printList(list);

  return (0);
}
