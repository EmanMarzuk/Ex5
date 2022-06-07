#include "BST.h"
#include "TreePrintLibrary.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{
	BST* bst = (BST*)malloc(sizeof(BST));
	// Checking the functions with empty tree
	initBST(bst);
	printTreeInorder(bst);
	destroyBST(bst);
	findIndexNFromLast(bst, 1);
	//Adding elements to the tree
	insertBST(bst, 5);
	insertBST(bst, 8);
	insertBST(bst, 9);
	insertBST(bst, 2);
	insertBST(bst, 4);
	insertBST(bst, 1);
	// Checking the functions with tree
	print_ascii_tree(bst->root);
	printf("tree inorder: ");
	printTreeInorder(bst);
	printf("\n");
	printf("find index: ");
	printf("%d\n", findIndexNFromLast(bst, 2));
	
	if (sameHeightLeaves(bst))	printf("The tree has the same height leaves!\n");
	else  printf("The tree does not have the same height leaves!\n");
	
	return 0;
}