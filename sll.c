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
    printf("\nSingle Linked List!");
    int choice = 0;
    int position = 0;
    int count = 0;
    int value = 0;
    struct node *new_node = NULL;
    while (1) {
        printf("\n1.Create\n2.Insert at beginning\n3.Insert at end\n4.Insert at position\n5.Delete from first\n6.Delete at end\n7.Delete at position\n8.Search\n9.Print\n10.End");
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
            printf("\nInsert at beginning!");
            new_node = allocate();
            if (new_node == NULL) {
                printf("\nMalloc failure!");
                exit(1);
            } else {
                printf("\nEnter the value for node!");
                scanf("%d",&new_node->data);
                new_node->next = head;
                head = new_node;
            }         
            break;
            case 3:
            printf("\nInsert at end!");
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
            case 4:
            printf("\nInsert at position!");
            printf("\nTell me a position!");
            scanf("%d",&position);
            new_node = allocate();
            if (new_node == NULL) {
                printf("\nMalloc failure!");
                exit(1);
            } else {
                printf("\nEnter the value for node!");
                scanf("%d",&new_node->data);
                struct node* curr = head;
                while (curr != NULL) {
                    count++;
                    if (position-1 > count) {
                        curr = curr->next;
                    } else {
                        break;
                    }
                }
                new_node->next = curr->next;
                curr->next = new_node;
            }
            break;
            case 5:
            printf("\nDelete from first!");
            if (head == NULL) {
                printf("\nList empty!");
            }
            struct node *ele = head;
            struct node *next = head->next;
            free(ele);
            ele = NULL;
            head = next;
            break;
            case 6:
            printf("\nDelete at end!");
            struct node* h = head;
            struct node* p = head;
            if (h == NULL) {
                printf("\nList is empty!");
            }
            if (h->next == NULL) {
                free(h);
                h = NULL;
                head = NULL;
            }
            else {
                while (h->next != NULL) {
                    p = h;
                    h = h->next;
                }
                p->next = NULL;
                free(h);
            }
            break;
            case 7:
            count = 0;
            printf("\nDelete at position!");
            printf("\nEnter position to delete from");
            scanf("%d",&position);
            struct node* cr = head;
            struct node* pr = head;
            while (cr != NULL) {
                count++;
                pr = cr;
                if (count == position-1) {
                    pr->next = pr->next->next;
                    free(cr->next);
                    cr->next = NULL;
                    break;
                }
                cr = cr->next;
            }
            break;
            case 8:
            printf("\nSearch!");
            printf("\nEnter the value to search!");
            scanf("%d",&value);
            count = 0;
            struct node* c = head;
            while (c != NULL) {
                count++;
                if (c->data == value) {
                    printf("\nValue %d present in %d position",value,count);
                    break;
                }
                if (c->next == NULL) {
                    printf("\nValue %d not found!",value);
                }
                c = c->next;
            }
            break;
            case 9:
            printf("\nList!");
            struct node* current = head;
            printf("\n");
            while (current != NULL) {
                printf("%d->",current->data);
                current = current->next;
            }
            printf("NULL");
            break;
            case 10:
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
