#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left rotate binary tree
 * @tree: pointer to the root node
 * Description: 22. Rotate left
 * Return: pointer to new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new = NULL;

	if ((tree->left == NULL) && (tree->right == NULL))
	{
		return (tree);
	}

	new = tree->right;
	tree->parent = new;
	new->parent = NULL;
	new->left = tree;
	tree->right = NULL;
	tree = new;
	return (tree);
}
