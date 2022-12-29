#include <stdio.h>
#include <stdlib.h>

#pragma region BSTNode

#pragma region BSTFunctionPrototypes

/* Tree function prototypes*/
struct BSTNode* insertIntoBSTree(struct BSTNode*, int);
struct BSTNode* newBSTNode(int);
void inorderTraversal(struct BSTNode*);
void preorderTraversal(struct BSTNode*);
void postorderTraversal(struct BSTNode*);
void deallocateTree(struct BSTNode*);
struct BSTNode* searchInBSTree(struct BSTNode*, int);
int getTreeHeight(struct BSTNode*);

#pragma endregion BSTFunctionPrototypes

#pragma region BSTNodeStructs

/**
 * \struct Represents a binary search tree node.
*/

struct BSTNode {
    int data; /* Node data */
    struct BSTNode *left; /* Pointer to the binary search tree's left subtree */  
    struct BSTNode *right; /* Pointer to the binary search tree's right subtree */
};

#pragma endregion BSTNodeStructs

#pragma region BSTFunctionImplementations

/**
 * \brief Inserts a new value (together with its node) to a binary search tree.
 * \param root Root of the binary search tree.
 * \param data Value to be inserted in the binary search tree.
 * \return Unchanged pointer to the root of the binary search tree.
*/
struct BSTNode* insertIntoBSTree(struct BSTNode *root, int data) {
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
struct BSTNode* searchInBSTree(struct BSTNode *root, int data) {
    if (root == NULL) return NULL;
    if (data < root->data) {
        searchInBSTree(root->left, data);
    } else if (data > root->data) {
        searchInBSTree(root->right, data);
    } else {
        return root;
    }
}

/**
 * \brief Creates a new binary search tree node.
 * \param data The data to be inserted into the node.
 * \returns Pointer to the binary search tree node.
*/
struct BSTNode* newBSTNode(int data) {
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
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    } 

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void preorderTraversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void deallocateTree(struct BSTNode *root) {
    if (root == NULL) return;
    deallocateTree(root->left);
    deallocateTree(root->right);
    free(root);
}


/**
 * \brief Function that removes a node from a binary search tree root.
 * @param raiz Pointer to the binary search tree root.
 * @param data Data you want to remove from the tree.
 * @returns Pointer to the new tree root.
*/
struct BSTNode* removeFromBSTree(struct BSTNode *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        root->left = removeFromBSTree(root->left, data);
    } else if (data > root->data) {
        root->right = removeFromBSTree(root->right, data);
    } else {
        // Base case - root with no children
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
            return NULL;
        } else if (root->left == NULL) {
            struct BSTNode *temp = root->right;
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode *temp = root->left;
            return temp;
        } else {
            // Following the instructions for nodes with two children
            struct BSTNode *parent, *temp;
            parent = root;
            temp = root->left;
            while(temp->right != NULL){  //Looking for the biggest leaf in the left
                parent = temp;
                temp = temp->right;
            }
            root->data = temp->data;
            if(parent->data == root->data){ 
                parent->left = temp->left;
            } else {
                parent->right = temp->left;
            }
        }
    }
    return root;
}

/**
 * \brief Gets the height of a tree.
 * \param root Pointer to the root node.
 * \return Tree height
*/
int getTreeHeight(struct BSTNode *root) {
    if (root == NULL) return 0;

    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);

    if (leftHeight >= rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

#pragma endregion BSTFunctionImplementations

#pragma endregion BSTNode

#pragma region Queue

#pragma region QueueStructs

/**
 * \struct Represents a linked list with queue data
*/
struct QueueNode {
    struct BSTNode *data;
    struct QueueNode *next;
};

/**
 * \struct Represents a queue
*/
struct Queue {
    struct QueueNode *front, *rear;
};

#pragma endregion QueueStructs

#pragma region QueueFunctionPrototypes

struct QueueNode* newQueueNode(struct BSTNode*);
struct Queue* createQueue();
void enqueue(struct Queue*, struct BSTNode*);
struct BSTNode* dequeue(struct Queue*);

#pragma endregion QueueFunctionPrototypes

#pragma region QueueFunctionImplementations

/**
 * \brief Creates a new queue node.
 * \param data Data to be added into the node.
 * \return Pointer to the queue node.
*/
struct QueueNode* newQueueNode(struct BSTNode *data) {
    struct QueueNode* q = malloc(sizeof *q);
    q->data = data;
    q->next = NULL;
    return q;
}

/**
 * \brief Creates a new queue.
 * \return Pointer to the new queue.
*/
struct Queue* createQueue() {
    struct Queue *q = malloc(sizeof *q);
    q->front = NULL;
    q->rear = NULL;
    return q;
}

/**
 * \brief Enqueue some data.
 * \param q Pointer to the queue.
 * \param data Data to enqueue.
*/
void enqueue(struct Queue *q, struct BSTNode *data) {
    struct QueueNode *temp = newQueueNode(data);
    
    if (q->rear == NULL) {
        q->front = temp;
        q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

/**
 * \brief Dequeue an element.
 * \param q Pointer to the queue.
*/
struct BSTNode* dequeue(struct Queue *q) {
    if (q->front == NULL) return NULL;

    struct QueueNode *temp = q->front;
    struct BSTNode *res = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return res;
}

#pragma endregion QueueFunctionImplementations

#pragma endregion Queue

void handleTestCase(int);
void printBSTLevelOrder(struct BSTNode*);

void printBSTLevelOrder(struct BSTNode *root) {
    struct Queue *queue = createQueue();
    struct BSTNode* temp = root;

    while (temp) {
        printf("%d ", temp->data);

        if (temp->left) {
            enqueue(queue, temp->left);
        }

        if (temp->right) {
            enqueue(queue, temp->right);
        }

        temp = dequeue(queue);
    }
}

void handleTestCase(int caseNumber) {
    struct BSTNode* root = NULL;
    int treeSize;

    scanf("%d", &treeSize);
    int input;
    
    for (int i = 0; i < treeSize; i++) {
        scanf("%d", &input);
        root = insertIntoBSTree(root, input);
    }

    printf("Case %d:\n", caseNumber);
    printBSTLevelOrder(root);
    printf("\n");    
    
    deallocateTree(root);
}

int main() {
    int testCaseCount;
    scanf("%d", &testCaseCount);

    for (int i = 0; i < testCaseCount; i++) {
        handleTestCase(i+1);
    }
    
    return 0;
}