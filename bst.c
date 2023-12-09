#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node* allocate() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("\nMalloc failure!");
        exit(1);
    }
    return new_node;
}
struct node* insert(struct node *temp, struct node *root) {
    if (root == NULL) {
        root = temp;
    } else {
        if (temp->data < root->data) {
            root->left = insert(temp,root->left);
        } else if (temp->data > root->data){
            root->right = insert(temp,root->right);
        }
    }
    return root;
}
void print_inorder(struct node *t) {
    if (t == NULL) return;
    if (t != NULL) {
        print_inorder(t->left);
        printf("%d:",t->data);
        print_inorder(t->right);
    }
}
void print_preorder(struct node *t) {
    if (t == NULL) return;
    if (t != NULL) {
        printf("%d:",t->data);
        print_preorder(t->left);
        print_preorder(t->right);
    }
}
void print_postorder(struct node *t) {
    if (t == NULL) return;
    if (t != NULL) {
        print_postorder(t->left);
        print_postorder(t->right);
        printf("%d:",t->data);
    }
}
void search(struct node *root, int value) {
    if (root == NULL) {
        printf("\nValue not found!");
        return;
    }
    else {
        if (root->data == value) {
            printf("\nValue found!");
            return;
        } else {
            if (value < root->data)
                search(root->left,value);
            else
            search(root->right,value);
        }
    }
}
struct node *delete(struct node*root, int value) {
    if (root == NULL) {
        printf("\nValue not found to be deleted!");
        return NULL;
    }
    if (value < root->data) {
        root->left = delete(root->left, value);
    } else if (value > root->data) {
        root->right = delete(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left != NULL && root->right == NULL) {
            struct node * y  = root->left;
            free(root);
            return y;
        } else if (root->right != NULL && root->left == NULL) {
            struct node *z =  root->right;
            free(root);
            return z;
        } else {
            struct node *succ_parent = root;
            struct node *succ = root->right;
            while (succ->left != NULL) {
                succ_parent = succ;
                succ = succ->left;
            }
            if (succ_parent == root) {  
                root->right = succ->right;
            } else {
                root->left = succ->right;
            }
            root->data = succ->data;
            free(succ);
        }   
    }
    return root;
}
void main() {
    printf("\nBinary Search Tree!");
    int choice = 0;
    int position = 0;
    int count = 0;
    int value = 0;
    struct node *new_node = NULL;
    struct node *nn = NULL;
    while (1) {
        printf("\n1.Create\n2.Insert\n3.Delete\n4.Search\n5.Print Inorder\n6.Print PreOrder\n7.Print PostOrder\n6..End");
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
                new_node->left = NULL;
                new_node->right = NULL;
                root = new_node;
            }
            break;
            case 2:
            printf("\nInsert!");
            nn = allocate();
            if (new_node == NULL) {
                printf("\nMalloc failure!");
                exit(1);
            } else {
                printf("\nEnter the value for node!");
                scanf("%d",&nn->data);
                insert(nn,root);
            }         
            break;
            case 3:
            printf("\nDelete!");
            printf("\nEnter value to delete!");
            scanf("%d",&value);
            delete(root,value);
            break;
            case 4:
            printf("\nSearch!");
            printf("\nEnter the value to search!");
            scanf("%d",&value);
            search(root,value);
            break;
            case 5:
            printf("\nBST Inorder!");
            printf("\n");
            print_inorder(root);
            break;
            case 6:
            printf("\nBST Preorder!");
            printf("\n");
            print_preorder(root);
            break;
            case 7:
            printf("\nBST Postorder!");
            printf("\n");
            print_postorder(root);
            break;
            case 8:
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
