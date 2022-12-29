#include <stdio.h>
#include <stdlib.h>

#pragma region BSTNode

#pragma region BSTFunctionPrototypes

/* Tree function prototypes*/
struct BSTNode* newBSTNode(char);
void postorderTraversal(struct BSTNode*);

#pragma endregion BSTFunctionPrototypes

#pragma region BSTNodeStructs

/**
 * \struct Represents a binary search tree node.
*/

struct BSTNode {
    char data; /* Node data */
    struct BSTNode *left; /* Pointer to the binary search tree's left subtree */  
    struct BSTNode *right; /* Pointer to the binary search tree's right subtree */
};

#pragma endregion BSTNodeStructs

#pragma region BSTFunctionImplementations

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

void postorderTraversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    } 

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c", root->data);
}

#pragma endregion BSTFunctionImplementations

#pragma endregion BSTNode

int index;

struct BSTNode* mountTree(char *inorder, char *preorder, int inStart, int inEnd)
{

	int inorderIndex;

	if (inStart > inEnd)
		return NULL;

	struct BSTNode *node = newBSTNode(preorder[index++]);
	if (inStart == inEnd) return node;

    for (int i = inStart; i <= inEnd; i++) {
        if (node->data == inorder[i]) {
            inorderIndex = i;
        }
    }

	node->left = mountTree(inorder, preorder, inStart, inorderIndex - 1);
	node->right = mountTree(inorder, preorder, inorderIndex + 1, inEnd);

	return node;
}

void handleTestCase() {
    char LINE[500];
    int nodeCount;
    struct BSTNode* result = NULL;

    fgets(LINE, sizeof(LINE), stdin);
    sscanf(LINE, "%d %*s %*s", &nodeCount);

    char *inorder = malloc(nodeCount * sizeof *inorder);
    char *preorder = malloc(nodeCount * sizeof *preorder);
    
    sscanf(LINE, "%*d %s %s", preorder, inorder);
    result = mountTree(inorder, preorder, 0, nodeCount-1);
    postorderTraversal(result);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        index = 0;
        handleTestCase();
    }
}