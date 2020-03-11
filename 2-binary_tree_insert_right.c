#include "binary_trees.h"

/**
 * binary_tree_insert_right - function inserts a right child
 * @parent: pointer to the parent node
 * @value: value to put into right child
 * Description: 2. Insert right
 * Return: see below
 * 1. upon success, return pointer to right child
 * 2. upon fail, return NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/* declare pointer to right child */
	binary_tree_t *right_child = NULL;

	/* allocate memory for right child but if fail, return NULL */
	right_child = malloc(sizeof(binary_tree_t));
	if (right_child == NULL)
		return (NULL);

	/* assign value or NULL to right child */
	right_child->n = value;
	right_child->left = NULL;
	right_child->right = NULL;
	right_child->parent = NULL;

	/* if there's no parent */
	if (parent == NULL)
		return (NULL);

	/* if there's no right child */
	if (parent->right == NULL)
	{
		parent->right = right_child;
		right_child->parent = parent;
		return (right_child);
	}

	/* if there's already a right child */
	if (parent->right != NULL)
	{
		right_child->parent = parent;
		right_child->right = parent->right;
		(parent->right)->parent = right_child;
		parent->right = right_child;
		return (right_child);
	}

	return (NULL);
}
