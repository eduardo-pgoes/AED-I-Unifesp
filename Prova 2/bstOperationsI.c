#include <stdio.h>
#include <stdlib.h>

#pragma region BSTNode

/* Tree function prototypes*/
struct BSTNode* insertIntoBSTree(struct BSTNode*, char);
struct BSTNode* newBSTNode(char);
void inorderTraversal(struct BSTNode*);
void preorderTraversal(struct BSTNode*);
void postorderTraversal(struct BSTNode*);
void deallocateTree(struct BSTNode*);

/**
 * \struct Represents a binary search tree node.
*/

struct BSTNode {
    char data; /* Node data */
    struct BSTNode *left; /* Pointer to the binary search tree's left subtree */  
    struct BSTNode *right; /* Pointer to the binary search tree's right subtree */
};

/**
 * \brief Inserts a new value (together with its node) to a binary search tree.
 * \param root Root of the binary search tree.
 * \param data Value to be inserted in the binary search tree.
 * \return Unchanged pointer to the root of the binary search tree.
*/
struct BSTNode* insertIntoBSTree(struct BSTNode *root, char data) {
    if (root == NULL) {
        return newBSTNode(data);
    }

    if (data < root->data) {
        root->left = insertIntoBSTree(root->left, data);
    } else if (data > root->data) {
        root->right = insertIntoBSTree(root->right, data);
    }

    return root;
}

/**
 * \brief Searches an element in a binary search tree.
 * \param root Pointer to the root node.
 * \param data The element you want to search.
 * \return 1 - found the element, 0 - element not found
*/
int searchInBSTree(struct BSTNode *root, char data) {
    if (root == NULL) return 0;
    if (data < root->data) {
        searchInBSTree(root->left, data);
    } else if (data > root->data) {
        searchInBSTree(root->right, data);
    } else {
        // data == root->data
        return 1;
    }
}

/**
 * \brief Creates a new binary search tree node.
 * \param data The data to be inserted into the node.
 * \returns Pointer to the binary search tree node.
*/
struct BSTNode* newBSTNode(char data) {
    struct BSTNode *temp = malloc(sizeof *temp);

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void inorderTraversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    } 

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->data);
}

void preorderTraversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    }

    printf("%c ", root->data);

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void deallocateTree(struct BSTNode *root) {
    if (root == NULL) return;
    deallocateTree(root->left);
    deallocateTree(root->right);
    free(root);
}

#pragma endregion BSTNode

struct stackNode {
    struct stackNode *next;
    struct BSTNode *data;
};

/* Stack function prototypes */
int isEmpty(struct stackNode*);
int push(struct stackNode**, struct BSTNode*) ;
struct BSTNode* pop(struct stackNode**);
struct stackNode* newStackNode(struct BSTNode*);

/**
 * \brief Tells you if the stack is empty or not.
 * \param s Stack
 * \returns True or false (1, 0)
*/
int isEmpty(struct stackNode *head) {
    return (head == NULL) ? 1 : 0;
}

/**
 * \brief Pushes a new element into the stack.
 * \param s The stack you want to push this new item into
 * \param data The data you want to push into the stack
*/
int push(struct stackNode **head, struct BSTNode* data) {
    struct stackNode *ptr = newStackNode(data);

    // Couldn't allocate space for the next entry
    if (ptr == NULL) {
        printf("Stack overflow.");
        return 0;
    }

    if (isEmpty(*head)) {
        ptr->data = data;
        ptr->next = NULL;
        *head = ptr;
        return 1;
    }

    // LIFO -> new stack's next pointer should point to the old stack, since it's at the top
    ptr->next = *head;
    *head = ptr;

    return 1;
}

/**
 * \brief Creates a new stack node.
 * \param data The data you want to insert in the new node.
 * \return Pointer to the stack node.
*/
struct stackNode* newStackNode(struct BSTNode *data) {
    struct stackNode *s = malloc(sizeof *s);
    s->data = data;
    s->next = NULL;
    return s;
}

/**
 * \brief Pops an element out of the stack
 * \param s Stack
 * \return Element out of stack (LIFO)
*/
struct BSTNode* pop(struct stackNode **head) {
    struct stackNode *temp;
    struct BSTNode *res; // Result we'll return

    if (isEmpty(*head)) {
        printf("Stack empty.");
        return 0;
    }

    temp = *head;
    res = temp->data;
    (*head) = (*head)->next;

    return res;
}

#pragma endregion Stack


int main() {
    struct BSTNode* root = NULL;

    char LINE[256];

    int treeSize = 0;

    while (fgets(LINE, sizeof(LINE), stdin)) {
        if (LINE[0] == 'I') {
            if (LINE[1] == ' ') {
                root = insertIntoBSTree(root, LINE[2]);
                treeSize++;
            } else { // 'IN'FIXA
                inorderTraversal(root);
                printf("\n");
            }
        } else if (LINE[0] == 'P') {
            if (LINE[1] == ' ') { // "P z", por exemplo
                if (searchInBSTree(root, LINE[2])) {
                    printf("%c existe\n", LINE[2]);
                } else {
                    printf("%c nao existe\n", LINE[2]);
                }
            } else if (LINE[1] == 'R') { // "PR"efixa
                preorderTraversal(root);
                printf("\n");
            } else if (LINE[1] == 'O') { // "PO"sfixa
                postorderTraversal(root);
                printf("\n");
            }
        }
    }

    return 0;
}