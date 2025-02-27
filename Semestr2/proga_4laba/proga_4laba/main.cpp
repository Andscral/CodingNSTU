#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* findSovpad(struct Node* head1, struct Node* head2) {
    struct Node* current1 = head1;
    struct Node* current2 = head2;

    struct Node* result = NULL;
    struct Node* back = NULL;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data == current2->data) {
            // список для результатов
            if (result == NULL) {
                result = (struct Node*)malloc(sizeof(struct Node));
                result->data = current1->data;
                result->prev = NULL;
                result->next = NULL;
                back = result;
            }
            //если в результатах уже есть ответы
            else {
                back->next = (struct Node*)malloc(sizeof(struct Node));
                back->next->prev = back;
                back->next->data = current1->data;
                back->next->next = NULL;
                back = back->next;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        else if (current1->data < current2->data) {
            current1 = current1->next;
        }
        else {
            current2 = current2->next;
        }
    }

    return result;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

    //списки
    head1->data = 2;
    head1->prev = NULL;
    head1->next = second;

    second->data = 4;
    second->prev = head1;
    second->next = third;

    third->data = 4;
    third->prev = second;
    third->next = fourth;

    fourth->data = 6;
    fourth->prev = third;
    fourth->next = NULL;

    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* sixth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* seven = (struct Node*)malloc(sizeof(struct Node));

    head2->data = 2;
    head2->prev = NULL;
    head2->next = fifth;

    fifth->data = 4;
    fifth->prev = head2;
    fifth->next = sixth;

    sixth->data = 5;
    sixth->prev = fifth;
    sixth->next = seven;

    seven->data = 6;
    seven->prev = sixth;
    seven->next = NULL;

    struct Node* result = findSovpad(head1, head2);

    printf("Result: ");
    printList(result);

    return 0;
}
