#include "binary_trees.h"

bst_t *minimum(bst_t *root);

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
	/* declare and initialize pointers */
	bst_t *new = NULL, *current = NULL;

	/* if there's no root node */
	if (root == NULL)
		return (NULL);

	/* first search for value on the left subtree */
	/* then search for value on the right subtree */
	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else
	{
		/* if there's no child or one right child */
		if (root->left == NULL)
		{
			new = root->right;
			free(root);
			return (new);
		}
		/* if there's no child or one left child */
		else if (root->right == NULL)
		{
			new = root->left;
			free(root);
			return (new);
		}
		/* if there's two children */
		current = minimum(root->right);
		root->n = current->n;
		root->right = bst_remove(root->right, current->n);
	}
	return (root);
}

/**
 * minimum - searches for minimum value in BST
 * @root: pointer to root node
 * Description: search in left subtree only
 * Return: minimum value
 */
bst_t *minimum(bst_t *root)
{
	bst_t *current = root;

	while ((current) && (current->left))
	{
		current = current->left;
	}
	return (current);
}
