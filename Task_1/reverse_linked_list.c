#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* previous = NULL;
    struct ListNode* current = head;

    while (current != NULL) {
        struct ListNode* nextNode = current->next;

        current->next = previous;
        previous = current;
        current = nextNode;
    }

    return previous;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }

    printf("\n");
}

int main() {
    struct ListNode* first = malloc(sizeof(struct ListNode));
    struct ListNode* second = malloc(sizeof(struct ListNode));
    struct ListNode* third = malloc(sizeof(struct ListNode));
    struct ListNode* fourth = malloc(sizeof(struct ListNode));
    struct ListNode* fifth = malloc(sizeof(struct ListNode));

    first->val = 1;
    first->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = fourth;

    fourth->val = 4;
    fourth->next = fifth;

    fifth->val = 5;
    fifth->next = NULL;

    printf("Original List: ");
    printList(first);

    struct ListNode* reversed = reverseList(first);

    printf("Reversed List: ");
    printList(reversed);

    free(fifth);
    free(fourth);
    free(third);
    free(second);
    free(first);

    return 0;
}