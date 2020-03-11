#include "binary_trees.h"

/**
 * bst_remove - removes a node from a BST
 * @root: pointer to the root node
 * @value: value to remove
 * Description: 28. BST - Remove
 * Return: see below
 * 1. upon success, return pointer to new root node
 * 2. upon fail, return NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	/* declare and initialize pointers for child and root */
	bst_t *child = NULL, *current = NULL;
	
	/* if there's no root node */
	if (root == NULL)
		return (NULL);

	/* if the value is in the root node */
	if (root->parent == NULL)
	{
		if (root->left == NULL)
		{
			child = root->right;
			free(root);
			return (child);
		}
		if (root->right == NULL)
		{
			child = root->left;
			free(root);
			return (child);
		}
	}

	/* first, search for value on the left subtree */
	/* next, search for value on the right subtree */
	/* last, search if node has no or one child */
	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			child = root->right;
			free(root);
			return (child);
		}
		if (root->right == NULL)
		{
			child = root->left;
			free(root);
			return (child);
		}
	}

	current = root;
	while ((current) && (current->right != NULL))
	{
		current = current->right;
	}
	root->n = current->n;
	root->right = bst_remove(root->right, current->n);
	return (root);
}
