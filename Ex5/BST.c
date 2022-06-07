#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

// MACRO question 2
#define MALLOC(p) \
do \
{ \
  if ( !( (p) = malloc(sizeof(*(p))))) \
  { \
    printf("Insufficient memory\n"); \
    exit(1); \
  } \
}\
while(0)


// question 1
void initBST(BST* bst) {
	bst->root = (TreeNode*)malloc(sizeof(TreeNode));
	bst->root = NULL;
	
	
}

// question 2
TreeNode* newNode(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->element = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert(TreeNode* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->element)
		node->left = insert(node->left, key);
	else if (key > node->element)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}
void insertBST(BST* bst, int value) {
	
	bst->root = insert(bst->root, value);
}

// question 3
void temp3(TreeNode* node)
{
	if (node != NULL)
	{
		temp3(node->left);
		printf(" %d", node->element);
		temp3(node->right);
	}
}
void printTreeInorder(BST* bst) {
	if (bst->root == NULL)	printf("The Tree is empty!");
	else     temp3(bst->root);
}

// question 4
void temp4(TreeNode* node) {
	if (node == NULL)	return;
		
	temp4(node->left);
	temp4(node->right);
	free(node);
}
void destroyBST(BST* bst) {
	temp4(bst->root);
}

// question 5
int findIndexFromLastTemp(TreeNode* bst, int N) {
	if (bst == NULL)	return;

	if (N > 0) {
		findIndexFromLastTemp(bst->right, --N);
		findIndexFromLastTemp(bst->left, --N);
	}
	else
	{
		return bst->element;
	}
}

int findIndexNFromLast(BST* bst, int N) {
	if (bst->root == NULL) {
		printf("The Tree is empty!\n");
		return 0;
	}
	else   return findIndexFromLastTemp(bst->root, N);
}



// question 6 A
int height(TreeNode* node)
{
	if (node == NULL)
		return 0;
	else {
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}
int temp6(TreeNode* root, int level, int* leafLevel) {
	if (root == NULL)  return 1;

	// If a leaf node is encountered
	if (root->left == NULL && root->right == NULL)
	{
		// When a leaf node is found first time
		if (*leafLevel == 0)
		{
			*leafLevel = level; // Set first found leaf's level
			return 1;
		}

		// If this is not first leaf node, compare its level with
		// first leaf's level
		return (level == *leafLevel);
	}

	// If this node is not leaf, recursively check left and right subtrees
	return temp6(root->left, level + 1, leafLevel) &&
		temp6(root->right, level + 1, leafLevel);
}
int sameHeightLeaves(BST* bst) {
	int temp = 0;
	int level = height(bst->root);
	int res = temp6(bst->root, level, &temp);
	return res;
}