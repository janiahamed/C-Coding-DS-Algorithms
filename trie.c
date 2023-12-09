#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define N 26
struct node {
    char data;
    struct node *children[N];
    int is_leaf;
};
struct node *root;
struct node* allocate(char data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("\nMalloc failure!");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        new_node->children[i] = NULL;
    }
    new_node->data = data;
    new_node->is_leaf = 0;

    return new_node;
}
struct node* insert(struct node *root, char *input) {
    struct node *temp = root;
    int position = 0;
    printf("\nWord input is :%s",input);
    for (int i = 0; input[i] != '\0';  i++) {
        position = (int)input[i] - 'a';
        printf("\nPosition is :%d",position);
        if (temp->children[position] == NULL) {
            temp->children[position] = allocate(input[i]);
            printf("\nCharacter : %c",temp->data);
        } else {
            //Do nothing as character is already present
        }
        temp = temp->children[position];
    }
    temp->is_leaf = 1;
    return root;
}
void print(struct node* root) {
    // Prints the nodes of the trie
    if (!root)
        return;
    struct node* temp = root;
    printf("%c -> ", temp->data);
    for (int i=0; i<N; i++) {
        print(temp->children[i]); 
    }
}
void search(struct node *root, char *word) {
    struct node *temp = root;
    int position = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        position = (int)word[i] - 'a';
        if (temp->children[position] == NULL) {
            printf("\nWord not found");
            return;
        } else {
            temp = temp->children[position];
        }
    }
    if (temp->is_leaf == 1) {
        printf("\nWord found!");
    } else {
        printf("\nIncomplete word found!");
    }
}
bool is_complete_word(char *word) {
    struct node *temp = root;
    int position = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        position = (int)word[i] - 'a';
        if (temp->children[position] != NULL) {
            temp = temp->children[position];
        }
    }
    return (temp->is_leaf == 1) ? true:false;
}
int check_divergence(struct node *root, char *prefix) {
    struct node *temp = root;
    int c_index = 0;
    for (int i= 0; i < strlen(prefix); i++) {
        int position = prefix[i] - 'a';
        if (temp->children[position]) {
            for (int j = 0; j < N; j++) {
                if (j != position && temp->children[j]) {
                    c_index =  i;
                    break;
                }
            }
            temp = temp->children[position];
        }
    }
    return c_index;
}
char* common_prefix (struct node *root, char *word) {
    char *prefix = (char *)malloc((1 + strlen(word))*sizeof(char));
    strcpy(prefix, word);
    int index = check_divergence(root, prefix);
    if (index >= 0) {
        prefix[index] = '\0';
        prefix = (char *)realloc(prefix, (1+index) * sizeof(char));
    }
    return prefix;
}
void delete(struct node *root, char *word) {
    printf("\nDeletion in progress!");
    if (!is_complete_word(word)) {
        printf("\nIncomplete word cant be deleted!");
        return;
    }
    struct node *temp = root;
    char* cp = common_prefix(root, word);
    int i = 0;
    for (i = 0; cp[i] != '\0'; i++) {
        int position = (int)cp[i] - 'a';
        if (temp->children[position] != NULL) {
            temp = temp->children[position];
        } else {
            return;
        }
    }
    int len = strlen(word);
    for (; i < len; i++) {
        int position = (int)word[i] - 'a';
        if (temp->children[position] != NULL) {
            struct node* rem = temp->children[position];
            temp->children[position] = NULL;
            free(rem);
        }

    }
}
void main() {
    printf("\nTrie!");
    int choice = 0;
    int position = 0;
    int count = 0;
    int value = 0;
    struct node *new_node = NULL;
    char input[100];
    while (1) {
        printf("\n1.Create\n2.Insert Word\n3.Delete Word\n4.Search Word\n5.Print Dictionary\n6.End");
        printf("\nSelect a choice:");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
            printf("\nCreate!");
            new_node = allocate('\0');
            if (new_node == NULL) {
                printf("\nMalloc failure!");
                exit(1);
            } else {
                root = new_node;
            }
            break;
            case 2:
            printf("\nInsert Word!");
            printf("\nEnter a word to add to dictionary!");
            scanf("%s",input);
            insert(root, input);
            break;
            case 3:
            printf("\nDelete Word!");
            printf("\nEnter a word to delete from dictionary!");
            scanf("%s",input);
            delete(root, input);
            break;
            case 4:
            printf("\nSearch Word!");
            printf("\nEnter a word to search in dictionary!");
            scanf("%s",input);
            search(root, input);
            break;
            case 5:
            printf("\nPrint Dictionary!");
            print(root);
            break;
            case 6:
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
