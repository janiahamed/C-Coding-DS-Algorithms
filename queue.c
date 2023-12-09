#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head;
struct node* allocate() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("\nMalloc failure!");
        exit(1);
    }
    return new_node;
}
void main() {
    printf("\nQueue!");
    int choice = 0;
    int position = 0;
    int count = 0;
    int value = 0;
    struct node *new_node = NULL;
    while (1) {
        printf("\n1.Create\n2.Enqueue\n3.Dequeue\n4.Print\n5.End");
        printf("\nSelect a choice:");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
            printf("\nCreate!");
            new_node = allocate();
            if (new_node == NULL) {
                printf("\nMalloc failure!");
                exit(1);
            } else {
                printf("\nEnter the value for node!");
                scanf("%d",&new_node->data);
                new_node->next = NULL;
                head = new_node;
            }
            break;
            case 2:
            printf("\nEnqueue!");
            new_node = allocate();
            if (new_node == NULL) {
                printf("\nMalloc failure!");
                exit(1);
            } else {
                printf("\nEnter the value for node!");
                scanf("%d",&new_node->data);
                struct node* cur = head;
                while (cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = new_node;
                new_node->next = NULL;
            }
            break;
            case 3:
            printf("\nDequeue!");
            if (head == NULL) {
                printf("\nList empty!");
            }
            struct node *ele = head;
            struct node *next = head->next;
            free(ele);
            ele = NULL;
            head = next;
            break;
            case 4:
            printf("\nList!");
            struct node* current = head;
            printf("\n");
            while (current != NULL) {
                printf("%d->",current->data);
                current = current->next;
            }
            printf("NULL");
            break;
            case 5:
            printf("\nThank you!");
            exit(1);
            break;
            default:
            printf("\nTry again!");
            break;
        }
        choice = 0;
    }
}
